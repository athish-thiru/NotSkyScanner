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
We have written the project in a manner such that each algorithm or traversal runs seperately and outputs are written to a specified file name in the `outputs/` folder. Follow the instructions specified below.

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

## Team
Athish Thiruvengadam (athisht2)

Arya Haria (aharia2)

Sanjivani Sharma (sharma74)

Jasmehar Kochhar (kochhar4)