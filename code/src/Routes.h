//routes.h
#pragma once
#include <string>
#include <vector>
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
    double distance(int source_number, int dest_number);
    std::vector<int>src_vect;
    std::vector<int>dest_vect;
   


};
