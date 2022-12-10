#include <catch2/catch_test_macros.hpp> 
#include "../code/src/graph.h"

using namespace std;

TEST_CASE("BFS Test Case 1", "[BFS]") {
    Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(100);
    std::vector<std::string> expected = {"Arya Airport", "Athish Airport", "Mount Hagen Kagamuga Airport", "Nadzab Airport"};

    REQUIRE(temp == expected);
}

TEST_CASE("BFS Test Case 2 Terminal Vertex", "[BFS]") {
    Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(3500);
    std::vector<std::string> expected = {"Nadzab Airport"};

    REQUIRE(temp == expected);
}

TEST_CASE("BFS Test Case 3 Non Existent Airport", "[BFS]") {
    Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(45);
    std::vector<std::string> expected = {};

    REQUIRE(temp == expected);
}

TEST_CASE("BFS Test Case 4 Not Connected Vertex", "[BFS]") {
    Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(42);
    std::vector<std::string> expected = {"Lonely Airport"};

    REQUIRE(temp == expected);
}

TEST_CASE("BFS Test Case 5", "[BFS]") {
    Graph test_graph = Graph("../data/testAirports.dat", "../data/testRoutes.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(250);
    std::vector<std::string> expected = {"Athish Airport", "Mount Hagen Kagamuga Airport", "Nadzab Airport"};

    REQUIRE(temp == expected);
}
