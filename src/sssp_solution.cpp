#include "sssp_solution.h"
#include "graph.h"

// Constructor for SSSPSolution class
SSSPSolution::SSSPSolution(const std::vector<int>& dists) : distances(dists) {}

// output method used to print the solution to an output stream 
std::ostream &SSSPSolution::output(std::ostream& os) const {

    os << "Single Source Shortest Path: \n"; 

    // loop through each vertex in the graph
    for (size_t i = 0; i < distances.size(); i++) {

        // for each vertex, output its index (i) and distance from source vertex
        os << "Vertex " << i << " - Distance: " << distances[i] << "\n"; 

    }
    // return the output stream
    return os; 
}
