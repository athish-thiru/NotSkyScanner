//Graphs Class

//#include "airport_graph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

/*
//default constructor
Graph::Graph(){
}
//construct the vertices 
//such that each airport object is connected with its ID

void addEdge(vector <pair<srting, int> > adj, int source_number, string destination_number, int distance)
{
    adj[source_number].push_back(make_pair(dest_number, distance));
}
void addAllEdges(){
//open file
//i = 0

    for(i = 0; i<source.size(); i++){
    int source_number = source[i]; //gives the index of the source airport as in the airport vector (i is the index per line)
    int dest_number = destination[i];//gives the index of the destination as in the airport vector (i is the index per line)
    int distance = distance[i];//distance between the airports (i is index per line)
    addEdge(adj, source, destination, distance);
    }
}

/* /THIS FUNCTION IS RELOCATED TO ROUTES. CPP/


double distance(int source_number, int dest_number){
    source_lat = airport[source_number].getlat();
    source_long = airport[source_number].getlon();
    dest_lat = airport[dest_number].getlat();
    dest_long = airport[dest_number].getlon();
    
    source_lat = toRadians(source_lat);
    source_long = toRadians(source_long);
    dest_lat = toRadians(dest_lat);
    dest_long = toRadians(dest_long);

    long double d_long = long2 - long1;
    long double d_lat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(d_long / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;
     
    // Calculate the result
    long double distance = ans * R;
 
    return distance;
}

*/