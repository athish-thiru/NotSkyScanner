/*source: https://leetcode.com/problems/path-with-maximum-probability/solutions/732293/Dijkstra's-algorithm-implementation-C++/ */
#include <bits/stdc++.h>
#include "Graph.h"
#include "Routes.h"

using namespace std;

class Dijkstra
{

    public:
   //  vector<vector<pair<int, int>>> buildGraph(int n, vector<vector<int>>& edges, vector<int>& weights) ;
    /*helper function to print the solution*/
    void printSolution(vector<int>& dist);
    /*shortest path function for adjacency list representation*/
    void setList(vector<vector<pair<int, int>>>& graph, int src);

};
