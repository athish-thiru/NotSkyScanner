//Graphs Class
#include "Graph.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

#include <bits/stdc++.h>


using namespace std;


/*
Parameterized Graph Constructor
airportsFile is the input file which contains all the airports
routesFile is the input file which contains all the airport routes
*/
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
    // Checks if the provided source number is a given airport
    if (routes_.GetAirports()[source_number].getName() == "UNKNOWN") {
        return {};
    }
    if (adjList_[source_number].size() == 0) {
        return {routes_.GetAirports()[source_number].getName()};
    }
    std::queue<int> queue;
    std::vector<bool> visited(adjList_.size(), false);
    queue.push(source_number);
    visited[source_number] = true;
    std::vector<std::string> path;

    while (!queue.empty()) {
        int source_airport = queue.front();
        if (routes_.GetAirports()[source_airport].getName() == "UNKNOWN") {
            queue.pop();
            continue;
        }
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


/* 
The function finds the shortest path between a source airport and destination airport
It does so using the Dijkstra's algorithm
src is the OpenFlights ID for the Source Airport
destination is the OpenFlights ID for the Destination Airport
*/
vector< pair<int, int> > Graph::Dijkstra(int start,int destination)
    {
    cout << "\nGetting the shortest path from " << start << " to all other nodes.\n";
    vector<pair<int, int> > dist; // First int is dist, second is the previous node. 
    
    int n = adjList_.size();// Initialize all source->vertex as infinite.
    for(int i = 0; i < n; i++)
        {
        dist.push_back(make_pair(1000000007, i)); // Define "infinity" as necessary by constraints.
        }
        
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > priorityQ;// Create a Priority Q.
    
    priorityQ.push(make_pair(start, 0));
    dist[start] = make_pair(0, start);;
    
    while(priorityQ.empty() == false)// While priorityQ isn't empty
        {
        int u = priorityQ.top().first;// Get min distance vertex from priorityQ which is u
        priorityQ.pop();
        
        
        for(int i = 0; i < adjList_[u].size(); i++)// Visit all of u's neighbours
            {
            int v = adjList_[u][i].first;
            int weight = adjList_[u][i].second;
            
            // If the distance to v is shorter by going through u...
            if(dist[v].first > dist[u].first + weight)
                {
                // Update the distance of v.
                dist[v].first = dist[u].first + weight;
                // Update the previous node of v.
                dist[v].second = u;
                priorityQ.push(make_pair(v, dist[v].first));// Insert v into the priorityQ. 
                }
            }
        }
    PrintShortestPath(dist,start,destination);
    return dist;
    }
    
void Graph::PrintShortestPath(vector< pair<int, int> > dist, int start,int destination)
    {
        if(dist[destination].first == 1000000007){
            cout<<"Oops it looks like there is no path"<< endl;
        }
        else{
        cout << "The distance from node " << start << " to node " << destination << " is: " << dist[destination].first << endl;
        
        int currnode = destination;
        cout << "The path is: " << currnode;
        int count;
        while(currnode != start)
            {
            currnode = dist[currnode].second;
            cout << " <- " << currnode;
            }
        cout << endl << endl;
        }
    }



/* Betweenness centrality implementation */
vector <int>Graph::betweennessCentrality(/*what should be taken as argument to return the bc value?*/ ) {

vector <int> count (Airport.size());  //vector to hold frequency of shortest paths passing through each airport
std:: fill (count.begin(), count.end(), 0);  //initialise count for all airports to 0
std::vector<std::pair<int, int>> output; 

//running Dijkstra's algorithm on every pair of nodes in the graph
for (int i = 0; i < adjList_.size(); i++) {
  for (int j = 0; j < adjList_[i].size(); j++) {
    pair<int, int> edge = adjList_[i][j];
    int start_ = edge.first;
    int dest_ = edge.second;
    // run Dijkstra's algorithm with start node and destination node as arguments
    output = Dijkstra(start_, dest_);
  }
}

//increment count whenever a node is incremented
for (int i = 0; i< output.size(); i++)
{
       for (int j = 0; j< output[i].size();j++)
          {
  	    count[i]++;
   	  }
}


  // Print the counts
  for (int i = 0; i < count.size(); i++) {
    cout << "Node " << i << " appears " << count[i] << " times" << endl;
  }

int number_elem = adjList_.size();
int number_pairs = number_elem * (number_elem - 1)/2;
    
vector <int> bc_node (Airport.size()); 
std:: fill (bc_node.begin(), bc_node.end(), 0);
    for (int i = 0; i < count.size(); i++){
 bc_node[i] = count[i]/number_pairs;
}

  // Print the betweenness centrality of each node
  for (int i = 0; i < bc_node.size(); i++) {
    cout << "Node " << i << " appears " << bc_node[i] << " times" << endl;
  }

return bc_node;

}

    

/*
Converts a vector into a csv file format
input is the vector of strings
filename is the name of the outputted file
*/
void Graph::writeToFile(std::vector<std::string> input, std::string filename) {
    std::ofstream outputFile(filename);

    for (size_t j = 0; j < input.size(); j++) {
        if (j == input.size() - 1) {
            outputFile << input[j] << std::endl;
        } else {
            outputFile << input[j] << ",";
        }
    }
    outputFile.close();
}




