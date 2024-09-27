#include "mst_solution.h"
#include "graph.h"
#include <iostream>

// Constructor that initializes the mstEdges vector and totalWeight
// mstEdges contains edges forming the MST, totalWeight the sums of their weights
MSTSolution::MSTSolution(const std::vector<Edge>& edges, int weight)
    : mstEdges(edges), totalWeight(weight) {}

// Method to output the solution of MST problem
// it prints each edge in the MST and the total weight to the provided os

std::ostream &MSTSolution::output(std::ostream &os) const {
 
    os << "Minimum Spanning Tree Edges:\n";
    
    // iterate over mstEdges vector and print each edge
    for (const Edge& edge : mstEdges) {

        os << edge.source << " -- " << edge.destination
            << " [weight: " << edge.weight << "]\n";

    }
    os << "Total weight of MST: " << totalWeight << "\n";
    
    return os;  // return the output stream
}
