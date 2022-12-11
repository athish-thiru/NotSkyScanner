#pragma once
#include <string>
#include <vector>
#include "Routes.h"

using namespace std; 

class Graph {
    public:
    Graph(string airportsFile, string routesFile);
    Graph(Routes routes);
    void addEdge(int source_number, int destination_number, long double distance);
    void addAllEdges();
    void printGraph(int V);
    std::vector<std::string> BFS(int source_number);
    void Dijkstra(int src);
    void printSolution(vector<int>& dist);
    void writeToFile(std::vector<std::vector<std::string>> input, std::string filename);

    private:
    Routes routes_;
    std::vector<std::vector<std::pair<int, long double>>> adjList_;
    
};