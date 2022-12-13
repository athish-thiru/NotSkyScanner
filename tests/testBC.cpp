#include <catch2/catch_test_macros.hpp> 
#include "../code/src/Graph.h"

using namespace std;

TEST_CASE ("Betweenness Centrality Score test case 1", "[betweennessCentrality]"){
Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
test_graph.addAllEdges();
vector<float> BCtest = testGraph.betweennessCentrality();
vector<float> expected_val = {};
  
REQUIRE (BCtest == expected_val); 

}

TEST_CASE ("Betweenness Centrality test case 2", "[betweennessCentrality]"){
Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
test_graph.addAllEdges();
vector<float> BCtest = testGraph.betweennessCentrality();
vector<float> expected_val = {};
  
REQUIRE (BCtest == expected_val); 

}

TEST_CASE ("Betweenness Centrality Score test case 3", "[betweennessCentrality]"){
Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
test_graph.addAllEdges();
vector<float> BCtest = testGraph.betweennessCentrality();
vector<float> expected_val = {};
  
REQUIRE (BCtest == expected_val); 

}


TEST_CASE ("Betweenness Centrality Score test case 4", "[betweennessCentrality]"){
Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
test_graph.addAllEdges();
vector<float> BCtest = testGraph.betweennessCentrality();
vector<float> expected_val = {};
  
REQUIRE (BCtest == expected_val); 

}

