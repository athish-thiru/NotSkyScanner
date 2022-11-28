#include <catch2/catch_test_macros.hpp> 
#include "../code/src/Routes.h"
#include "../code/src/graph.h"
#include "../code/src/airport.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;



TEST_CASE("Skips /N values", "[Routes = 1]") {
//test from 1 to 10 - this test must skip a /N value and all distances must be calculated 
    vector<int> ans_source_id;
    vector<int> ans_destination_id;
    vector<double> ans_distance;

    Routes routes;

    vector<int> test_source_id = {2965,2966,2966,2968,2968,4029,4029,4029,6156,6156};
    vector<int> test_destination_id = {2990,2990,2962,2990,4078,2990,6969,6160,2952,2990};
    vector<double> test_distance = {4418.96,12717.7,4287.81,436.354,5265.3,18702.8,18664.9,18702.8,3407.11,4220.92};

    for(int i; i<10; i++){
        ans_source_id.push_back(routes.GetSourceNumbers()[i]);
        ans_destination_id.push_back(routes.GetDestinationNumbers()[i]);
        ans_distance.push_back(routes.GetDistances()[i]);
    }

    // for(int i; i<10; i++){
    //     std::cout << routes.GetDistances()[i] <<endl;
    // }
   // std::cout << routes.GetDistances()[i] <<endl;

    REQUIRE(test_source_id == ans_source_id);
    REQUIRE(test_destination_id == ans_destination_id);
    REQUIRE(test_distance == test_distance);
}

TEST_CASE("No extra values in any vector/ all the data has been parsed", "[Routes = 1]") {

    Routes routes;
    std::cout << routes.GetSourceNumbers().size() <<endl;

    REQUIRE(routes.GetSourceNumbers().size() == routes.GetDestinationNumbers().size());
    REQUIRE(routes.GetDestinationNumbers().size() == routes.GetDistances().size());
    REQUIRE(routes.GetSourceNumbers().size() == routes.GetDistances().size());
}



