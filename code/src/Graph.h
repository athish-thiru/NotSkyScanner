#pragma once
#include <string>
#include <vector>
#include "Routes.h"
#include "airport.h"

using namespace std; 

class Graph {
    public:
    Graph();
    vector<Airport> setVector();
    void addEdge(vector <pair<int, long double> > adj, int source_number, int destination_number, long double distance);
    void addAllEdges();
    vector <pair<int, long double> > adj;
    void printGraph(vector<pair<int,long double> > adj[], int V);
    // void listAdjacentNodes(vector<pair<int,long double> > adj[], int m);

    private:
    Routes routes_;
};
