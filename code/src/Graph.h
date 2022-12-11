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
    void printGraph(int V);
    std::vector<std::string> BFS(int source_number);
    vector< pair<int, int> > DijkstraSP(int start,int destination);
    void PrintShortestPath(vector< pair<int, int> > dist, int start,int destination);
    
    private:
    Routes routes_;
    std::vector<std::vector<std::pair<int, long double>>> adjList_;
};
