//Graphs Class

#include "Routes.h"
#include "Graph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;


//construct the vertices 
//such that each airport object is connected with its ID
Graph::Graph() {
    Routes routes;
    routes_ = routes;
    std::cout << "IN GRAPH: " << routes_.GetSourceNumbers()[0] << " " << routes_.GetDestinationNumbers()[0] << " " << routes_.GetDistances()[0] << std::endl;
}

void Graph::addEdge(int source_number, int destination_number, long double distance)
{
    adj_[source_number] = (make_pair(destination_number, distance));
}

void Graph::addAllEdges(){
    for(int i = 0; i< routes_.GetDestinationNumbers().size(); i++){
    int source_number = routes_.GetSourceNumbers()[i]; //gives the index of the source airport as in the airport vector (i is the index per line)
    int dest_number = routes_.GetDestinationNumbers()[i]; //gives the index of the destination as in the airport vector (i is the index per line)
    long double distance = routes_.GetDistances()[i]; //distance between the airports (i is index per line)
    addEdge(source_number, dest_number, distance);
    }
}

void Graph::printGraph(int V)
{
    /*
    for (int i = 0; i < V; i++)
    {
        cout << "source airport " << i << " is connected to \n";
        for (auto it = adj_[i].begin(); it!=adj_[i].end(); it++)
        {
            int v = it->first;
            long double w = it->second;
            cout << "\tdestination " << v << " with distance"
                 << w << "\n";
        }
        cout << "\n";
    }
    */
}

