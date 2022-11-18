#pragma once
#include <string>
#include <vector>
#include "/workspaces/cs225/FinalProject/NotSkyScanner/code/src/Routes.h"
#include "/workspaces/cs225/FinalProject/NotSkyScanner/code/src/airport.h"

using namespace std; 

class Graph {
    public:
    Graph();
    void addEdge(vector <pair<int, long double> > adj, int source_number, int destination_number, long double distance);
    void addAllEdges();
    vector <pair<int, long double> > adj;
    void printGraph(vector<pair<int,long double> > adj[], int V);
    // void listAdjacentNodes(vector<pair<int,long double> > adj[], int m);

    private:
    Routes routes_;
};
