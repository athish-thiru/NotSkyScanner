#include <catch2/catch_test_macros.hpp> 
#include <iostream>
#include "../code/src/airport.h"
#include "../code/src/graph.h"
#include <sstream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


TEST_CASE("Parsing First Element", "[Edge Case 1]") {
    Graph test_graph;
    vector<Airport> test = test_graph.setVector();

    REQUIRE(test[1].getName() == "Goroka Airport");
    REQUIRE(test[1].getCity() == "Goroka");
    REQUIRE(test[1].getLat() == 145.391998291);
    REQUIRE(test[1].getLon() == -6.081689834590001);
    REQUIRE(test[1].getIATA() == "GKA");
}

TEST_CASE("Parsing Last Element", "[Edge Case 2]") {
    Graph test_graph;
    vector<Airport> test = test_graph.setVector();

    REQUIRE(test[14110].getName() == "Melitopol Air Base");
    REQUIRE(test[14110].getCity() == "Melitopol");
    REQUIRE(test[14110].getLat() == 35.305);
    REQUIRE(test[14110].getLon() == 46.880001);
    // string st = "\" + "N";
    REQUIRE(test[14110].getIATA() == "\\N");
}

TEST_CASE("Parsing Random", "[Middle Case 1]") {
    Graph test_graph;
    vector<Airport> test = test_graph.setVector();

    REQUIRE(test[641].getName() == "Harstad/Narvik Airport, Evenes");
    REQUIRE(test[641].getCity() == "Harstad/Narvik");
    REQUIRE(test[641].getLat() == 16.678100585938);
    REQUIRE(test[641].getLon() == 68.491302490234);
    // string st = "\" + "N";
    REQUIRE(test[641].getIATA() == "EVE");
}

TEST_CASE("Parsing Random", "[Middle Case 2]") {
    Graph test_graph;
    vector<Airport> test = test_graph.setVector();

    REQUIRE(test[2997].getName() == "Chhatrapati Shivaji International Airport");
    REQUIRE(test[2997].getCity() == "Mumbai");
    REQUIRE(test[2997].getLat() == 72.8678970337);
    REQUIRE(test[2997].getLon() == 19.0886993408);
    // string st = "\" + "N";
    REQUIRE(test[2997].getIATA() == "BOM");
}