#include "airport_graph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

//parsing into src_vect here

//parsing into dest_vect here




double distance(int source_number, int dest_number){
    source_lat = airport[source_number].getlat();
    source_long = airport[source_number].getlon();
    dest_lat = airport[dest_number].getlat();
    dest_long = airport[dest_number].getlon();
    
    source_lat = toRadians(source_lat);
    source_long = toRadians(source_long);
    dest_lat = toRadians(dest_lat);
    dest_long = toRadians(dest_long);

    long double d_long = long2 - long1;
    long double d_lat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(d_long / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;
     
    // Calculate the result
    long double distance = ans * R;
 
    return distance;
}

//parsing into dist vect here
