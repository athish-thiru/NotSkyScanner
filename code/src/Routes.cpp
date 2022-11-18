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
for (size_t i = 0; i < dest_id.size(); i++)
        cout << dest_id[i] << endl;
        



double distance(int source_number, int dest_number){
    long double source_lat = airport[source_number].getlat();
    long double source_long = airport[source_number].getlon();
    long double dest_lat = airport[dest_number].getlat();
    long double dest_long = airport[dest_number].getlon();
    
    source_lat = toRadians(source_lat);
    source_long = toRadians(source_long);
    dest_lat = toRadians(dest_lat);
    dest_long = toRadians(dest_long);

    long double d_long = dest_long - source_long;
    long double d_lat = dest_lat - source_lat;
 
    long double ans = pow(sin(dlat / 2), 2) + cos(source_lat) * cos(dest_lat) * pow(sin(d_long / 2), 2);
 
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
void make_distance(){
    if(i = 0;i < dest_id.size(); i++){ //loop through src and destination for the id numbers, 
        dist_vect[i] = distance(stoi(src_id[i]), stoi(dest_id[i]));
    }
}
