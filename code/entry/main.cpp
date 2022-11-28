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
    test_graph.addAllEdges();
    test_graph.printGraph(2912);

    return 0;
} 
