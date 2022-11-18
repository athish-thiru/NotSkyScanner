//#include "airport_graph.h"
#include "Routes.h"
#include <math.h> 
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
//to test dest_id has corect values, uncomment following lines
/*for (size_t i = 0; i < dest_id.size(); i++)
        cout << dest_id[i] << endl;
        */
//to test src_id has correct values, uncomment following lines
/*for (size_t i = 0; i < src_id.size(); i++)
        cout << src_id[i] << endl;
        */



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
void make_distance(){
    if(i = 0;i < dest_id.size(); i++){ //loop through src and destination for the id numbers, 
        dist_vect[i] = distance(stoi(src_id[i]), stoi(dest_id[i]));
    }
}
