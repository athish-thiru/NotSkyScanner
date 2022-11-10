/Graphs Class

#include "airport_graph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;


//default constructor
Graph::Graph(){
}
//construct the vertices 
//such that each airport object is connected with its ID

void addEdge(vector <pair<int, int> > adj[], int source_number, int destination_number, int distance)
{
    adj[source_number].push_back(make_pair(destination_number, distance));
}
void addAllEdges(){
//open file
//i = 0

    for(i = 0; i<source.size(); i++)
    int source_number = source[i]; //index of the source airport as in the airport vector
    int destination_number = destination[i];//index of the destination as in the airport vector
    int distance = distance[i];//distance between the airports
    addEdge(adj, source, destination, distance);
}

double distance(int source_number, int destination_number){
    
}