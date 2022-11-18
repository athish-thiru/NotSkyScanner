//#include "airport_graph.h"
#include "Routes.h"
#include <cmath> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include <fstream>


using namespace std;


//parsing into src_vect here

//parsing into dest_vect here
Routes::Routes() {
    std::ifstream routesdata("routes.dat");
    std::vector<string>src_id;
    std::vector<string>dest_id;
    std::vector<long double>dist_vect;
    std::string line; 
    while (std::getline(routesdata, line))
    {
        // Line contains string of length > 0 then save it in vector
        if(line.size() > 0){
            stringstream ss(line);
            vector<string> v;
            while(ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        src_id.push_back(v[3]);
        dest_id.push_back(v[5]);
        }
    }
    for (size_t i = 0; i < dest_id.size(); i++) cout << dest_id[i] << endl;
}



double Routes::distance(int source_number, int dest_number){
    long double source_lat = airports[source_number].getLat();
    long double source_long = airports[source_number].getLon();
    long double dest_lat = airports[dest_number].getLat();
    long double dest_long = airports[dest_number].getLon();
    
    //source_lat = toRadians(source_lat);
    //source_long = toRadians(source_long);
    //dest_lat = toRadians(dest_lat);
    //dest_long = toRadians(dest_long);

    source_lat *= (3.14/180);
    source_long *= (3.14/180);
    dest_lat *= (3.14/180);
    dest_long *= (3.14/180);

    long double d_long = dest_long - source_long;
    long double d_lat = dest_lat - source_lat;
 
    long double ans = pow(sin(d_lat / 2), 2) + cos(source_lat) * cos(dest_lat) * pow(sin(d_long / 2), 2);
 
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
void Routes::make_distance(){
    for (size_t i = 0;i < dest_id.size(); i++){ //loop through src and destination for the id numbers, 
        dist_vect[i] = distance(src_id[i], dest_id[i]);
    }
}
