# Euler-and-Hamilton-Checker-
Overview:


The code is designed to perform Eulerian and Hamiltonian checks on a graph represented using an adjacency matrix. It determines whether the given graph has an Euler circuit or path and checks for the presence of a Hamiltonian circuit or path.

Classes and Structures:


VertexAndEdges:
Structure to hold information about edges between vertices.
EulerAndHamiltonian:
Class handling the operations related to Eulerian and Hamiltonian paths/circuits.


Variables:


adjacencyMatrix: 2D array storing edge information.
StoreSum: Array to store the sum of edges for each vertex.
pathArray: Array to store the path elements.
Functions and Methods:
EulerAndHamiltonian(): Constructor to initialize the graph.
AdjacencyMatrix(): Takes user input for edge data and builds the adjacency matrix.
PrintAdjacencyMatrix(): Prints the adjacency matrix.
EulerCheck(): Checks for Euler circuit or path.
EulerPath(start): Finds the Euler path using backtracking.
Path(): Prints the Euler path.
FindEulerPath(): Finds the Euler path if a circuit doesn't exist.
Hamiltonian(): Checks for Hamiltonian circuit or path.
VertexDuplicate(): Checks for duplicate vertices in the path.
ASCII Art:
The code includes an ASCII art representation for visualization purposes.

Main Function:


Displays ASCII art.
Creates an object of EulerAndHamiltonian class.
Offers menu-driven options:
Euler Check
Hamiltonian Check
Exit
Documentation Points:
Purpose:
Explain what the code aims to accomplish.

Usage:

How to use the program, input requirements, and expected outputs.
Algorithm Overview:
Describe the algorithms used for Eulerian and Hamiltonian checks.
Data Structures:
Describe the data structures used (adjacency matrix, arrays).
Error Handling:
Explain how errors or invalid inputs are handled.
Limitations:
Any known limitations or assumptions in the code's functionality.
![image](https://github.com/Najeebullah3124/Euler-and-Hamilton-Checker-/assets/147226547/2f6304b5-b5a1-404b-aeb2-be1b917aed3c)
![image](https://github.com/Najeebullah3124/Euler-and-Hamilton-Checker-/assets/147226547/45f3ec32-9279-405c-99b1-11271b909ad7)
