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
    vector< pair<int, int> > Dijkstra(int start,int destination);
    void PrintShortestPath(vector< pair<int, int> > dist, int start,int destination);
    void writeToFile(std::vector<std::string> input, std::string filename);
    
    private:
    Routes routes_;
    std::vector<std::vector<std::pair<int, long double>>> adjList_;
};
