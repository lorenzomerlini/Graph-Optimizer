#include "spsp_solution.h"
#include "graph.h"

// Constructor initialize the path and total weight of the shortest path
// path vector contain the sequence of nodes in the shortest path, cost represents the total weight of that path
SPSPSolution::SPSPSolution(const std::vector<int>& path, int cost) : path(path), totalWeight(cost) {}

// method to output the solution to Single Pair Shortest Path problem. 
// it prints the path and total cost to the provided output stream (os)
std::ostream &SPSPSolution::output(std::ostream &os) const {

    os << "Single Pair Shortest Path: \n"; 
    os << "Path: ";

    // iterate over the path vector and print each node
    for (size_t i = 0; i < path.size(); i++) {

        os << path[i]; 
        if (i != path.size() -1) {
            os << " -> "; 
            }
        }
    os << "\nTotal Cost of SPSP: " << totalWeight << "\n"; 
    return os;                  // return the output stream
}
