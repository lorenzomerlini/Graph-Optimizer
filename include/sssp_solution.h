#ifndef SSSP_SOLUTION_H
#define SSSP_SOLUTION_H

#include "problem_solution.h"                           // base class for problem solutions
#include <vector>

// SSSPSolution class definition, inherits from ProblemSolution - solution for SSSP problems
class SSSPSolution : public ProblemSolution {

private:
    // vector to store min distances from source node to every other node
    std::vector<int> distances;     

public: 
    // Constructor that takes a vector of distances as input - initialize distances member
    SSSPSolution(const std::vector<int>& dists); 

    // output method overrides pure virtual method from ProblemSolution base class 
    // takes an output stream reference and prints solution to that stream
    std::ostream& output(std::ostream& os) const override;

}; 

#endif // SSSP_SOLUTION_H