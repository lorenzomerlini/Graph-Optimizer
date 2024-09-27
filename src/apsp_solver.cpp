#include "apsp_solver.h"

/* APSPSolver is an implementation of ProblemSolver interface. 
Used to solve the All-Pairs Shortest Path problem (APSP). 
This method takes a const reference to a Graph obj as an argument 
and returns a pointer to ProblemSolution obj (APSPSolution obj)
Uses Floyd-Warshall algorithm to find the shortest paths between 
all pairs of nodes. */
std::unique_ptr<ProblemSolution> APSPSolver::solve(const Graph& graph) {

    int numVertices = graph.getNumVertices();               // obtain numVertices in currentGraph
    const int INF = std::numeric_limits<int>::max();        // infinite constant

    // initialize distance matrix with INF 
    std::vector<std::vector<int>> dist(numVertices, std::vector<int>(numVertices, INF)); 

    // populate the distance matrix with weight of edges in the graph
    for (int i = 0; i < numVertices; ++i) {
        
        for (const Edge& edge : graph.getAdjacencyList(i)) {

            dist[edge.source][edge.destination] = edge.weight; 
        }
        dist[i][i] = 0;     // distance from node itself it's 0
    }

    // Floyd-Warshall algorithm 
    for (int k = 0; k < numVertices; ++k) {                               

        for (int i = 0; i < numVertices; ++i) {                      // iterate on every starting node

            for (int j = 0; j < numVertices; ++j) {                 // iterate on every destination node
           

                if (dist[i][k] != INF && dist[k][j] != INF) {           // if exist a path between node k shorter than actual node   

                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]); 
                }
            }
        }
    }
    // create and return APSPSolution obj 
    return std::make_unique<APSPSolution>(dist); 
}