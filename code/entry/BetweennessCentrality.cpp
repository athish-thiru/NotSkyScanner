#include "../src/Graph.h"
#include <ctime>
#include <iostream>
#include <algorithm>

int main() {
    std::cout << "Loading Graph" << std::endl;
    Routes routes("../data/airports.dat", "../data/routes.dat");
    Graph test_graph("../data/airports.dat", "../data/routes.dat");
    test_graph.addAllEdges();

    std::string filename;
    std::cout << "Enter Filename: ";
    std::cin >> filename;

    std::cout << "Running Betweenness Centrality Algorithm" << std::endl;
    std::vector<float> betweennessValue = test_graph.betweennessCentrality(1000);

    int elem = (std::max_element(betweennessValue.begin(), betweennessValue.end()) - betweennessValue.begin());
    std::cout << "The Airport with the Highest Centrality Score: " << routes.GetAirports()[elem].getName() << std::endl;
    std::cout << "Centrality Score: " << betweennessValue[elem] << std::endl;

    test_graph.writeToFile(betweennessValue, "../output/" + filename);
    std::cout << "Centrality score for every node written to file" << std::endl;

    return 0;
}
