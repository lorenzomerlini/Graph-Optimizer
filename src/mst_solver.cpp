#include "mst_solver.h"
#include "mst_solution.h"
#include <memory>

/* MSTSolver is an implementation of ProblemSolver interface. 
It is used to solve the Minimum Spanning Tree (MST) problem. 
This method takes a const reference to a Graph object as an argument
and returns a pointer to ProblemSolution object (MSTSolution object)*/
std::unique_ptr<ProblemSolution> MSTSolver::solve(const Graph& graph) {

    int numVertices = graph.getNumVertices();           // Graph class method to retrieve numVertices 
    std::vector<Edge> mstEdges;                         // vector to store edges 
    int totalWeight = 0;                                

    std::vector<bool> inMST(numVertices, false);        // vector to keep track if vertex is in MST (initially all false)
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;    // priority queue to store edges based on their weight.
                                                                            // small weight = highest priority
    
    // start from vertex 0  
    inMST[0] = true;                                      
    for (const Edge& edge : graph.getAdjacencyList(0)) {                    // Graph class method to retrieve adjacency list

        pq.push(edge);                                  // push in pq all edges connected to starting vertex
    }
    
    // loop continues until pq is empty or MST contains (numVertices -1) edges
    while (!pq.empty() && mstEdges.size() < numVertices -1) {

        Edge minEdge = pq.top();                        // retrieve from pq edge with min weight
        pq.pop();                                       // remove it  

        int v = minEdge.destination;                    // destination vertex of the edge
        if (inMST[v]) continue;                         // if destination vertex is already in MST, skip it

        inMST[v] = true;                                 
        mstEdges.push_back(minEdge);                    // add edge --> MST 
        totalWeight += minEdge.weight;                  // sum weight in totalWeight

        // for each edge adjacent to newly added vertex, push the edge to pq if destination vertex not yet in MST
        for (const Edge& edge : graph.getAdjacencyList(v)) {

            if (!inMST[edge.destination]) {             // if adjacent vertex not in MST
                pq.push(edge);                          // push edge in pq
            }
        }
    }

   // return a new MSTSolution object containing the edges in the MST and the total weight of the MST 
    return std::make_unique<MSTSolution>(mstEdges, totalWeight); 
}