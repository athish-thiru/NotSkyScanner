//Graphs Class

#include "Routes.h"
#include "Graph.h"
#include <math.h> 
#include <float.h>
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

/*
Adds a single edge to the Adjacency List representation of the Graph
source_number is the OpenFlights ID for the Source Airport
destination_number is the OpenFlights ID for the Destination Airport
distance is the calculated distance between them
Note that the function only add an edge from source number to destination number since the graph is directed
*/
void Graph::addEdge(int source_number, int destination_number, long double distance) {
    bool exist = false;
    for (int i = 0; i < adjList_[source_number].size(); i++) {
        if ((adjList_[source_number][i].first == destination_number) && (adjList_[source_number][i].second == distance)) {
            exist = true;
        }
    }
    if (!exist) adjList_[source_number].push_back(make_pair(destination_number, distance));
}

/*
Adds all edges from the Route class that has been initialized to the Adjacency List
*/
void Graph::addAllEdges(){
    for(int i = 0; i< routes_.GetDestinationNumbers().size(); i++){
        int source_number = routes_.GetSourceNumbers()[i]; //gives the index of the source airport as in the airport vector (i is the index per line)
        int dest_number = routes_.GetDestinationNumbers()[i]; //gives the index of the destination as in the airport vector (i is the index per line)
        long double distance = routes_.GetDistances()[i]; //distance between the airports (i is index per line)
        addEdge(source_number, dest_number, distance);
    }
}

/*
The function prints a visual representation of the graph for a given node
source_number is the OpenFlights ID for the Source Airport
The function prints to standard out all the Airports connected to the input airport along with their distance
*/
void Graph::printGraph(int source_number) {
    if (adjList_[source_number].size() == 0) { // Checks if the provided source number is a given airport
        std::cout << "Airport does not exist" << std::endl;
        return;
    }
    cout << "Source Airport " << routes_.GetAirports()[source_number].getName() << " is connected to \n";
    for (auto it = adjList_[source_number].begin(); it!=adjList_[source_number].end(); it++)
    {
        int v = it->first;
        long double w = it->second;
        cout << "\tDestination " << routes_.GetAirports()[v].getName() << " with distance: " << w << "\n";
    }
    cout << "\n";
    std::cout << "NUMBER OF EDGES: " << adjList_[source_number].size() << std::endl;
}

/* 
The function implements a BFS traversal through the graph with the airport at the given source number Airport
source_number is the OpenFlights ID for the Source Airport
Returns a vector of Airports Names which highlighted the path traversed in a breath first manner
*/
std::vector<std::string> Graph::BFS(int source_number) {
    if (adjList_[source_number].size() == 0) { // Checks if the provided source number is a given airport
        std::cout << "Airport does not exist" << std::endl;
        return {};
    }
    std::queue<int> queue;
    std::vector<bool> visited(adjList_.size(), false);
    queue.push(source_number);
    visited[source_number] = true;
    std::vector<std::string> path;

    while (!queue.empty()) {
        int source_airport = queue.front();
        path.push_back(routes_.GetAirports()[source_airport].getName());
        queue.pop();
        std::vector<std::pair<int, long double>> neighbours = adjList_[source_airport];
        for (std::pair<int, long double>& neighbour: neighbours) {
            if (!visited[neighbour.first]) {
                queue.push(neighbour.first);
                visited[neighbour.first] = true;
            }
        }
    }
    return path;
}



//error it is deleting something that is already there

void Graph::Dijkstra(int src, int destination) { //change the graph 

        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first; // <distance, node>
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> unfinalized(comp);
        int n = adjList_.size();
        vector<int> dist(n, INT_MAX);
        vector<int> destination_vector(n, 0);
        dist[src] = 0;
        unfinalized.push({0, src});

        while (!unfinalized.empty()) {
            int u = unfinalized.top().second;
            unfinalized.pop();

            for (int i = 0; i < adjList_[u].size(); i++) {
                int v = adjList_[u][i].first, weight = adjList_[u][i].second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    unfinalized.push({dist[v], v});
                    //destination_vector[v] = u;
                }
            }
        }

        printSolution(dist, destination,destination_vector);
    }

    void Graph::printSolution(vector<int>& dist, int destination,vector<int> &destination_vector) {
        printf("Vertex \t\t Distance from Source\n"); 
        printf("%d \t\t %d\n", destination, dist[destination]);
        // for(unsigned i = 0; i<destination_vector.size(); i++){
        //     if(destination_vector[i] != 0){
        //         printf("%d\n",destination_vector[i]);
            //}
        //}
        
    }
