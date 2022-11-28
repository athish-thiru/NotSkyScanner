#include <iostream>
#include "../src/airport.h"
#include "../src/graph.h"
#include <sstream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<Airport> setVector();

int main() {
    
    std::cout << "Main is working" << std::endl;
    Graph test_graph;
    vector<Airport> test = test_graph.setVector();

    size_t count = 0;
    for (size_t i = 0; i < test.size(); i++) {
        std::cout << test[i].getCity() << std::endl;
        if (test[i].getCity() != "UNKNOWN") {
            count++;
        }
    }
    std::cout << "COUNT: " << count << std::endl;
    std::cout << "SIZE: " << test.size() << std::endl;

    return 0;
} 
