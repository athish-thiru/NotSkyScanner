//routes.h
#pragma once
#include <string>
#include <vector>
#include "airport.h"
//vector: source. openflights identifier
//vector: destination, open flights idenitifer
//indexed by line they are on
//will create distances vector

using namespace std; 
class Routes {
    private:
    std::vector<int> src_id_vect_;
    std::vector<int> dest_id_vect_;
    std::vector<double> dist_vect_;
    std::vector<Airport> airports_;

    

    public:
    Routes();
    vector<Airport> setVector();
    double distance(int source_number, int dest_number);
    const std::vector<int> GetSourceNumbers();
    const std::vector<int> GetDestinationNumbers();
    const std::vector<double> GetDistances();
    const std::vector<Airport> GetAirports();
    
    void make_distance();
};
