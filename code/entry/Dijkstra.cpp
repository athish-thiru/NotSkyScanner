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

    std::vector<std::pair<int, int>> outputVector = test_graph.Dijkstra(source_number, dest_number);

    std::vector<int> secondOutput = test_graph.PrintShortestPath(outputVector, source_number, dest_number);

    std::vector<std::string> pathVector;
    for (size_t i = 0; i < secondOutput.size(); i++) {
        pathVector.push_back(routes.GetAirports()[secondOutput[i]].getName());
    }

    test_graph.writeToFile(pathVector, "../output/" + filename);
    std::cout << "Path written to file" << std::endl;

    return 0;
}