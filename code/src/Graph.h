#pragma once
#include <string>
#include "routes.h"
#include "airport.h"
using namespace std; 

class Graph {
    public:
    void addEdge(vector <pair<srting, int> > adj[], int source_number, string destination_number, int distance);
    void addAllEdges();
    vector <pair<srting, long double> > adj;
    void printGraph(vector<pair<int,long double> > adj[], int V)
    void listAdjacentNodes(vector<pair<int,long double> > adj[], int m)
};
