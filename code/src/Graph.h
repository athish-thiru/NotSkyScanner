#pragma once
#include <string>
#include <vector>
#include "Routes.h"
#include "airport.h"

using namespace std; 

class Graph {
    public:
    Graph();
    Graph(string routesFile, string airportsFile);
    void addEdge(int source_number, int destination_number, long double distance);
    void addAllEdges();
    vector <pair<int, long double> > adj;
    void printGraph(int V);

    private:
    Routes routes_;
    std::vector<std::vector<std::pair<int, long double>>> adjList_;
};
