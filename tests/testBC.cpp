#include <catch2/catch_test_macros.hpp> 
#include "../code/src/Graph.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

#include <bits/stdc++.h>


using namespace std;

TEST_CASE ("Betweenness Centrality Score test case 1", "[betweennessCentrality]"){
Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
test_graph.addAllEdges();
vector<float> BCtest = test_graph.betweennessCentrality(5);
vector<float> expected_val;

for (int i = 0; i < 14111; i++) {
    expected_val.push_back(0);
}

REQUIRE (BCtest == expected_val); 

}

TEST_CASE ("Betweenness Centrality Score test case 2", "[betweennessCentrality]"){
Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
test_graph.addAllEdges();
vector<float> BCtest = test_graph.betweennessCentrality(5);
vector<float> expected_val(14111);

REQUIRE (BCtest == expected_val); 

}

TEST_CASE ("Betweenness Centrality Score test case 3", "[betweennessCentrality]"){
Graph test_graph = Graph("../data/airports.dat", "../data/routes.dat");
test_graph.addAllEdges();
vector<float> BCtest = test_graph.betweennessCentrality(5);
vector<float> expected_val = {0.1, 0.1, 0.2, 0.3, 0.9};

REQUIRE (BCtest[0] == expected_val[0]); 
REQUIRE (BCtest[1] == expected_val[1]); 
REQUIRE (BCtest[2] == expected_val[2]); 
REQUIRE (BCtest[3] == expected_val[3]); 
REQUIRE (BCtest[4] == expected_val[4]); 
}
