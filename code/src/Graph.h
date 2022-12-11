#pragma once
#include "Routes.h"

using namespace std; 

class Graph {
    public:
    Graph(string routesFile, string airportsFile);
    void addEdge(int source_number, int destination_number, long double distance);
    void addAllEdges();
    void printGraph(int V);
    std::vector<std::string> BFS(int source_number);
    void Dijkstra(int src, int destination);
    void printSolution(vector<int>& dist, int destination,vector<int> &destination_vector);
    void writeToFile(std::vector<std::string> input, std::string filename);

    private:
    Routes routes_;
    std::vector<std::vector<std::pair<int, long double>>> adjList_;
};
