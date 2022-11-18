#include <iostream>
#include "/workspaces/CS225/NotSkyScanner-main/NotSkyScanner/code/src/airport.h"
#include <sstream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<Airport> setVector();

int main() {
    
    std::cout << "Main is working" << std::endl;
    vector<Airport> test = setVector();

    return 0;
} 

vector<Airport> setVector() {
    std::ifstream airportdata("/workspaces/CS225/NotSkyScanner-main/NotSkyScanner/data/airports.dat");
    string line;
    
    vector<Airport> ans;
    ans.push_back(Airport());
    while (std::getline(airportdata, line)) {
        stringstream ss(line);
        vector<string> v;

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }   
        cout<<v[6]<<endl;
        Airport temp;
        temp.setLat(stod(v[7]));
        temp.setLon(stod(v[6]));
        string str = v[4];
        str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
        temp.setIATA(str);
        str = v[2];
        str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
        temp.setCity(str);
        str = v[1];
        str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
        temp.setName(str); 
        ans.push_back(temp);        
    }
    return ans;
}
