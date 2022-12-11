#include "../src/Graph.h"
#include <ctime>
#include <iostream>

int main() {
    std::cout << "Loading Graph" << std::endl;
    Graph test_graph("../data/airports.dat", "../data/routes.dat");
    test_graph.addAllEdges();

    int source_number;
    std::string filename;
    std::cout << "Enter OpenFlights ID to run BFS: "; 
    std::cin >> source_number;
    std::cout << "Enter Filename: ";
    std::cin >> filename;

    time_t bfs_start = std::time(NULL);
    std::vector<std::string> outputVector = test_graph.BFS(source_number);
    time_t bfs_stop = std::time(NULL);


    std::cout << "Took " << bfs_stop - bfs_start << " seconds to run BFS" << std::endl;
    if (outputVector.empty()) {
        std::cout << "The entered source number corresponds with an airport that doesn't exist" << std::endl;
    } else if (outputVector.size() == 1) {
        std::cout << "The entered source number corresponds with a terminal vertex" << std::endl;
    } else {
        test_graph.writeToFile(outputVector, "../output/" + filename);
        std::cout << "Path written to file" << std::endl;
    }

    return 0;
}