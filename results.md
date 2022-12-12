The output and correctness of each algorithm – You should summarize, visualize, or highlight some part of the full-scale run of each algorithm. Additionally, the report should briefly describe what tests you performed to confirm that each algorithm was working as intended.
 
The answer to your leading question – You should direct address your proposed leading question. How did you answer this question? What did you discover? If your project was ultimately unsuccessful, give a brief reflection about what worked and what you would do differently as a team.

Answer: Our project proposal outlined the leading question as follows:

“The data set that we have decided to use is the Open Flights database, which is an open-source data set of flight routes and airports. We plan to use this data to create a directed graph and use the distance between two airports as the weight for the edges. Finally, we will use this data to determine the shortest distance between any two airports using Dijkstra's algorithm. We will then use the Betweenness Centrality algorithm to determine which airport has the most number of shortest routes. Note that only those paths will be considered where an actual airline route operates.“

In short, we wanted to find a method to find the shortest path between any two airports, and determine the most efficient route to fly between two locations. 

For this purpose, we first parsed the given datasets, airports.dat and routes.dat, and stored our data in a graph built using an adjacency list. This was done in the routes.cpp file to push_back elements into the destination id and source id vectors after parsing routes.dat. The distance between two airports was calculated using the distance function and stored in the distance vector and finally by using the set_vector function we created a vector of Airports. set_vector parsed airports.dat to store the name, city, latitude, longitude and IATA information for each airport. The graph was then created in Graph.cpp using the addEdge and addAllEdges functions to create an adjacency list using our vectors with stored data.  

We used BFS and Dijkstra’s algorithm to traverse the graph and find the shortest path between any two vertices. BFS was implemented using a queue to push and pop data and mark vertices as visited. Dijsktra’s algorithm is implemented using a heap/priority queue (referred: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/). The outcome of these algorithms fulfilled the purpose of our project, and then the Betweenness Centrality algorithm was used to “rank” the airports by the number of shortest paths associated with each. All algorithms were implemented in Graph.cpp. 

We discovered that there are multiple implementations of solving the shortest path problem by Dijkstra’s algorithm, and one can even use sets for this purpose. Our project was ultimately successful, and we learnt a lot about correct methods of parsing, data storage and traversal.

