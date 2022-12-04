#include <catch2/catch_test_macros.hpp> 
#include <iostream>
#include "../code/src/airport.h"
#include "../code/src/graph.h"
#include "../code/src/routes.h"
#include <sstream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

TEST_CASE("BFS Test Case 1", "[BFS]") {
    Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(100);

    REQUIRE(temp == <"Arya Airport", "Athish Airport", "Mount Hagen Kagamuga Airport", "Nadzab Airport">);
}
