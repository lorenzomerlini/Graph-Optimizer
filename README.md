# Graph Optimizer
C++ application designed to efficently handle graph structures and solve common optimization problems on them. 

## Solvable Problems
Minimum Spanning Tree: the program computes the minimum spanning tree of a graph using Prim's algorithm. 

Single-Pair Shortest Path: the program calculates the shortest path between two specified vertices in a weighted graph using Dijkstra's algorithm. 

Single-Source Shortest Path: given a source vertex, the program computes the shortest path from the source to all other vertices in the graph. Using Dijkstra's algorithm. 

All-Pairs Shortest Path: the program solves for the shortest paths between every pair of vertices using Floyd-Warshall algorithm. 

## Key Features 
Users can import graphs from external text files located in the same directory of the program. 
The program reads a file with the following format: 
-Graph Name
-Number of vertices
-Number of edges
-Edges: triplet of integers representing the source, destination and weight.

IMPORTANT: the "istances" folder contains a number of graphs examples in the correct format. 

Graph representation: the graph is stored as an adjacency list, which is both space-efficent and allows for quick lookups of adjacent vertices. This representation supports undirected graphs, with bidirectional edges automatically added for every edge in the input. 

## Solution Handling 
Once a solution is computed, it can be displayed directly on the console or exported to a text file. 
Management: if a new graph is imported, the previous solution is automatically deleted, ensuring efficient memory use. 

## Memory Management
The project utilizes smart pointers to automatically manage dynamic memory. 
This ensures when a solution is no longer needed, it is deallocated without needing manual intervention. 

## Future Improvements
- Additional algorithms
- Graph visualization: include visualization tools to display the imported graphs and their solutions graphically.
- Graph editing: allow users to modify the graph directly within the application. 


