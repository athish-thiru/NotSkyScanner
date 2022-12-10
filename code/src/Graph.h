#pragma once
#include "Routes.h"
#include "airport.h"

using namespace std; 

class Graph {
    public:
    Graph();
    Graph(string routesFile, string airportsFile);
    void addEdge(int source_number, int destination_number, long double distance);
    void addAllEdges();
    void printGraph(int V);
    std::vector<std::string> BFS(int source_number);
    void Dijkstra(int src);
    void printSolution(vector<int>& dist);

    private:
    Routes routes_;
    std::vector<std::vector<std::pair<int, long double>>> adjList_;
};
