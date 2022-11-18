//Graphs Class

#include "/workspaces/cs225/FinalProject/NotSkyScanner/code/src/Routes.h"
#include "/workspaces/cs225/FinalProject/NotSkyScanner/code/src/Graph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;


//construct the vertices 
//such that each airport object is connected with its ID
Graph::Graph() {
    Routes routes;
    routes_ = routes;
}

void Graph::addEdge(vector <pair<int, long double> > adj, int source_number, int destination_number, long double distance)
{
    adj[source_number] = (make_pair(destination_number, distance));
}
void Graph::addAllEdges(){
//open file
//i = 0

    for(int i = 0; i< routes_.src_id.size(); i++){
    int source_number = routes_.src_id[i]; //gives the index of the source airport as in the airport vector (i is the index per line)
    int dest_number = routes_.dest_id[i];//gives the index of the destination as in the airport vector (i is the index per line)
    long double distance = routes_.dist_vect[i];//distance between the airports (i is index per line)
    addEdge(adj, routes_.src_id[i], routes_.dest_id[i], routes_.dist_vect[i]);
    }
}

void Graph::printGraph(vector<pair<int,long double> > adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "source airport " << i << " is connected to \n";
        for (auto it = adj[i].begin(); it!=adj[i].end(); it++)
        {
            int v = it->first;
            long double w = it->second;
            cout << "\tdestination " << v << " with distance"
                 << w << "\n";
        }
        cout << "\n";
    }
}

// void listAdjacentNodes(vector<pair<int,long double> > adj[], int m){

//     printf("%d", m);
//     for(int j = 0; j < adj[m].size(); ++j){
//         printf(" -> %d (w:%d)", adj[m][j].first, adj[m][j].second);
//     }

// }






