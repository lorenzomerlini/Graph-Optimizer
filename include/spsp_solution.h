#ifndef SPSP_SOLUTION_H 
#define SPSP_SOLUTION_H 

#include "problem_solution.h"
#include <vector> 

// SPSPSolution class definition
// Inherits from ProblemSolution and represents solution for SPSP problem
class SPSPSolution : public ProblemSolution {

private: 
    std::vector<int> path;      // stores the sequence of nodes in the shortest path 
    int totalWeight;            // stores the total weight of shortest path

public: 

    // Constructor that initialize the path and total weight members
    SPSPSolution(const std::vector<int>& path, int cost);

    // the output method overrides the pure virtual method from ProblemSolution base class 
    // it prints the solution details (path and total weight)
    std::ostream& output(std::ostream& os) const override;

}; 

#endif // SPSP_SOLUTION_H 