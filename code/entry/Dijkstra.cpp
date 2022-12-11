#include "../src/Graph.h"
#include <ctime>
#include <iostream>

int main() {
    std::cout << "Loading Graph" << std::endl;
    Routes routes("../data/airports.dat", "../data/routes.dat");
    Graph test_graph("../data/airports.dat", "../data/routes.dat");
    test_graph.addAllEdges();

    int source_number;
    int dest_number;
    std::string filename;
    std::cout << "Enter OpenFlights ID for Source Airport: "; 
    std::cin >> source_number;
    std::cout << "Enter OpenFlights ID for Destination Airport: ";
    std::cin >> dest_number;
    std::cout << "Enter Filename: ";
    std::cin >> filename;

    time_t dijkstra_start = std::time(NULL);
    std::vector<std::pair<int, int>> outputVector = test_graph.DijkstraSP(source_number, dest_number);
    time_t dijkstra_stop = std::time(NULL);
    std::cout << "Took " << dijkstra_stop - dijkstra_start << " seconds to run BFS" << std::endl;

    std::vector<std::string> pathVector;
    for (size_t i = 0; i < outputVector.size(); i++) {
        int source_number = outputVector[i].second;
        pathVector.push_back(routes.GetAirports()[i].getName());
    }

    test_graph.writeToFile(pathVector, "../output/" + filename);
    std::cout << "Path written to file" << std::endl;

    return 0;
}