#include <iostream>
#include "/workspaces/cs225/FinalProject/NotSkyScanner/code/src/airport.h"
#include "/workspaces/cs225/FinalProject/NotSkyScanner/code/src/graph.h"
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

    return 0;
} 
