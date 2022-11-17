#include "airport_graph.h"
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
  //  std::vector<string>src_id;
 //   std::vector<string>dest_id;
    std::string line;
    int counter = 0;
 while (std::getline(routesdata, line)) {   
//parse through line
 for (int i=0;i<line.size();i++){
     
      if(line[i]=',')
      {
          if (counter==3)
{//push string into source substr and substr into src ID

string substr;
substr[0]=line[i+1];
substr[1]=line[i+2];
substr[3]=line[i+3];
substr[4]=line[i+4];

//test why substr doesnt have line
for(size_t i=0;i<substr.size();i++){
cout<<substr[i]<<endl;
    
}
src_id.push_back(substr);
//cout<<"test"<<endl;
//once substr successfully gets line, test if vector has it              
// for (size_t i = 0; i < src_id.size(); i++)
//         cout << src_id[i] << endl;
}
if (counter==5)
{//push string into dest substr and substr into dest ID
string substr;
substr[0]=line[i+1];
substr[1]=line[i+2];
substr[3]=line[i+3];
substr[4]=line[i+4];
dest_id.push_back(substr);
//cout<<"test_5"<<endl;
}
      counter++;
      //cout<<"test"<<endl;
     // cout<<line[i]<<endl;
          
      }


}
}









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
