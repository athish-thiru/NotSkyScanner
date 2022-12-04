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
    Routes routes = Routes();
    routes_ = routes;
    std::vector<std::pair<int, long double>> row = {};
    std::vector<std::vector<std::pair<int, long double>>> adjList(routes.GetAirports().size(), row);
    adjList_ = adjList;
}

Graph::Graph(string routesFile, string airportsFile) {
    Routes routes = Routes(routesFile, airportsFile);
    routes_ = routes;
    std::vector<std::pair<int, long double>> row = {};
    std::vector<std::vector<std::pair<int, long double>>> adjList(routes.GetAirports().size(), row);
    adjList_ = adjList;
}

void Graph::addEdge(int source_number, int destination_number, long double distance) {
    bool exist = false;
    for (int i = 0; i < adjList_[source_number].size(); i++) {
        if ((adjList_[source_number][i].first == destination_number) && (adjList_[source_number][i].second == distance)) {
            exist = true;
        }
    }
    if (!exist) adjList_[source_number].push_back(make_pair(destination_number, distance));
}

void Graph::addAllEdges(){
    for(int i = 0; i< routes_.GetDestinationNumbers().size(); i++){
        int source_number = routes_.GetSourceNumbers()[i]; //gives the index of the source airport as in the airport vector (i is the index per line)
        int dest_number = routes_.GetDestinationNumbers()[i]; //gives the index of the destination as in the airport vector (i is the index per line)
        long double distance = routes_.GetDistances()[i]; //distance between the airports (i is index per line)
        addEdge(source_number, dest_number, distance);
    }
    std::cout << "LIST SIZE: " << adjList_.size() << std::endl;
}

void Graph::printGraph(int source_number) {
    cout << "Source airport " << routes_.GetAirports()[source_number].getName() << " is connected to \n";
    for (auto it = adjList_[source_number].begin(); it!=adjList_[source_number].end(); it++)
    {
        int v = it->first;
        long double w = it->second;
        cout << "\tDestination " << routes_.GetAirports()[v].getName() << " with distance: " << w << "\n";
    }
    cout << "\n";
    std::cout << "SIZE: " << adjList_[source_number].size() << std::endl;
}

