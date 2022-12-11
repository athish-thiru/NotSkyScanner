#include <iostream>
#include "../src/Graph.h"
#include <fstream>

using namespace std;

int main() {
    
    std::cout << "Main is working" << std::endl;
    
    Graph test_graph("../data/airports.dat", "../data/routes.dat");
    test_graph.addAllEdges();
    test_graph.printGraph(2912);
    test_graph.Dijkstra(2966,2990);



    Routes routes("../data/airports.dat", "../data/routes.dat");
    Graph testgraph("../data/airports.dat", "../data/routes.dat");

//test to see value stored correctly in vertex of graph
    testgraph.addEdge(routes.GetSourceNumbers()[0],routes.GetDestinationNumbers()[0],routes.GetDistances()[0]);

    testgraph.printGraph(routes.GetSourceNumbers()[0]);

    //test for skipping value with \N
testgraph.addEdge(routes.GetSourceNumbers()[7],routes.GetDestinationNumbers()[7],routes.GetDistances()[7]);
  testgraph.printGraph(routes.GetSourceNumbers()[7]);
    cout<<"previous value skipped due to \\N"<<endl;


    //test for multiple edges
    testgraph.addEdge(routes.GetSourceNumbers()[12],routes.GetDestinationNumbers()[12],routes.GetDistances()[12]);
     testgraph.addEdge(routes.GetSourceNumbers()[13],routes.GetDestinationNumbers()[13],routes.GetDistances()[13]);
      testgraph.addEdge(routes.GetSourceNumbers()[14],routes.GetDestinationNumbers()[14],routes.GetDistances()[17]);
      testgraph.printGraph(routes.GetSourceNumbers()[12]);


    return 0;
} 
