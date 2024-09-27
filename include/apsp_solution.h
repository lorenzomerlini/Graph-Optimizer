#ifndef APSP_SOLUTION_H 
#define APSP_SOLUTION_H 

#include "problem_solution.h"
#include <vector> 

/* APSPSolution class

It inherits from the abstract base class ProblemSolution and implements
the output method to display the distance matrix. */
class APSPSolution : public ProblemSolution {

private: 
    std::vector<std::vector<int>> dist;     // 2D vector to store distance matrix 

public: 
    // constructor: initialize the APSPSolution obj with the given distance matrix
    APSPSolution(const std::vector<std::vector<int>>& dist); 

    // output method - overrides the pure virtual method from ProblemSolution 
    // base class. Outputs the distance matrix 
    std::ostream& output(std::ostream& os) const override; 
}; 

#endif // APSP_SOLUTION_H