//routes.h
#pragma once
#include "airport.h"

using namespace std; 
class Routes {
    private:
    std::vector<int> src_id_vect_;
    std::vector<int> dest_id_vect_;
    std::vector<long double> dist_vect_;
    std::vector<Airport> airports_;

    

    public:
    Routes(string airportsFile, string routesFile);
    vector<Airport> setVector(string input);
    double distance(int source_number, int dest_number);
    std::vector<int> GetSourceNumbers();
    std::vector<int> GetDestinationNumbers();
    std::vector<long double> GetDistances();
    std::vector<Airport> GetAirports();
    
    void make_distance();
};
