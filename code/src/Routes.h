//routes.h
#pragma once
#include <string>
#include <vector>
#include "/workspaces/cs225/FinalProject/NotSkyScanner/code/src/airport.h"
//vector: source. openflights identifier
//vector: destination, open flights idenitifer
//indexed by line they are on
//will create distances vector

using namespace std; 
class Routes {
    private:
    int source_number;
    int dest_number;
    

    public:
    Routes();
    double distance(int source_number, int dest_number);
    std::vector<int>src_id;
    std::vector<int>dest_id;
    std::vector<int>dist_vect;
    std::string line; 
    void make_distance();

    vector<Airport> airports;
   


};
