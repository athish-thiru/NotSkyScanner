# SkyScanner

## Description
This project analyses the OpenFlights dataset by construcing a graph representation of the data. We then uses Algorithms like Dijksta's and Betweenness Centrality to make inferences about the data.

## Deliverables
* The code for the project can be found in the `code/` directory.
* The Team Contract, the Project Proposal and the Final Report can be found in the `documents/` directory.
* The datafiles can be found in the `data/` directory.
* The test cases we've written can be found in the `tests/` directory.
* The outputs for the executable can be found in the `output/` folder.

## Executable
We have written the project in a manner such that each algorithm or traversal runs seperately and outputs are written to a specified file name in the `output/` folder. Follow the instructions specified below.

1. With the root directory as you location create a build folder run `mkdir build`.

2. To create the MakeFile for the project run the `cmake ..` and then to compile the project run `make`.

    ### BFS

    1. The executable which provides the interface for BFS is `./bfs`.

    2. Specify the OpenFlights ID for the staring airport, a number between `1` and `14110` and then a file name to write the path traversed to like `BFSoutput.txt`.

    3. Sometimes the inputted number does not correspond to a real airport in the dataset. In this case the program will tell you as such and ask you to try again.

    ### Dijkstra

    1. The executable which provides the interface for BFS is `./dijkstra`.

    2. Specify the OpenFlights ID for the staring airport, the OpenFlights ID for the destination airport and then a file name to write the path traversed to like `Dijkstraoutput.txt`. The OpenFlights ID is once again a number from `1` to `14110`.

    3. Sometimes the inputted numbers does not correspond to real airports in the dataset. In this case the program will tell you as such and ask you to try again.

    ### Betweenness Centrality

    1. The executable which provides the interface for BFS is `./bc`.

    2. Specify a file name like `BCoutput.txt`. The program will calculate the Centrality Score for a subset of nodes in the graph and return the name of the Airport associated with the Highest Centrality Score.
    Betweeness centrality is run on subgraphs due to time constraints, our function was run on the entire dataset and shows the correct betweenness scores.

## Output
The `output/` directory already has the output to each one of the executable described above to give you an idea of what the output should like. These files are `BFSoutputFile.txt`, `DijkstraoutputFile.txt` and `BCoutputFile.txt`.

## Tests
We have also written tests which are written in the `tests/` directory. You can execute the entire testcase by running `./test` after you compile the project. You can also execute the testcases associated with each indivdiual part of the program with the following keywords after `./test`:

* `[BC]` for Betweenness Centrality.

* `[Dijkstra]` for Dijkstra's Algorithm.

* `[BFS]` for Breath First Search.

* `[Parsing]` to test the Data Parsing.

* `[Graph]` to test the Graph Representation.

### Presentation

[The video is linked here](https://youtu.be/31GNqtM8-DM)

## Team
Athish Thiruvengadam (athisht2)

Arya Haria (aharia2)

Sanjivani Sharma (sharma74)

Jasmehar Kochhar (kochhar4)
