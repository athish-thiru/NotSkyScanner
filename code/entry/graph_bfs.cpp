#include "../src/Graph.h"
#include <ctime>
#include <iostream>

int main() {
    std::cout << "Loading Graph" << std::endl;
    Graph test_graph("../data/airports.dat", "../data/routes.dat");
    test_graph.addAllEdges();

    int source_number;
    std::string filename;
    std::cout << "Enter OpenFlights ID for Source Airport: "; 
    std::cin >> source_number;
    std::cout << "Enter Filename: ";
    std::cin >> filename;

    std::vector<std::string> outputVector = test_graph.BFS(source_number);

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