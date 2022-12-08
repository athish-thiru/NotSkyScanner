/*source: https://leetcode.com/problems/path-with-maximum-probability/solutions/732293/Dijkstra's-algorithm-implementation-C++/ */
//works with independent graph in online ide, need to adapt to our graph, algorithm seems sufficient and simpler than others
#include "dijkstra.h"
#include <bits/stdc++.h>


using namespace std;

// vector<vector<pair<int, int>>> buildGraph(int n, vector<vector<int>>& edges, vector<int>& weights) {
//     vector<vector<pair<int, int>>> graph(n);
//     for (int i = 0; i < edges.size(); i++) {
//         vector<int> edge = edges[i];
//         graph[edge[0]].push_back({edge[1], weights[i]});
//         graph[edge[1]].push_back({edge[0], weights[i]});
//     }
//     return graph;
// }

void printSolution(vector<int>& dist) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < dist.size(); i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void setList(vector<vector<pair<int, long double>>>& graph, int src) {
        // graph: each pair<int, int> is <node, weight>
        int n = adjList_.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        set<pair<int, int>> unfinalized;  // <distance, node>
        for (int node = 0; node < n; node++)
            unfinalized.insert({node == src ? 0 : INT_MAX, node});

        while (!unfinalized.empty()) {
            pair<int, int> p = *(unfinalized.begin());
            unfinalized.erase(unfinalized.begin());
            int u = p.second;

            for (int i = 0; i < adjList_[u].size(); i++) {
                int v = adjList_[u][i].first, dist_vect_ = adjList_[u][i].second;
                if (dist[u] + dist_vect_ < dist[v]) {
                    // v cannot be finalized, so must be in finalized
                    unfinalized.erase(unfinalized.find({dist[v], v}));
                    dist[v] = dist[u] + dist_vect_;
                    unfinalized.insert({dist[v], v});
                }
            }
        }

        printSolution(dist);
    }
