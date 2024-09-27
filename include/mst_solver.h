#ifndef MST_SOLVER_H 
#define MST_SOLVER_H 

#include "problem_solver.h"
#include "graph.h"
#include <vector> 
#include <queue>
#include <memory>

class MSTSolution;                      // forward declaration of the MSTSolution class

// MSTSolver class definition
// Inherits from ProblemSolver and implements the solve method for MST problem
class MSTSolver : public ProblemSolver {

public:
    // solve function overrides the pure virtual method from ProblemSolver base class 
    // it takes a const reference to a Graph obj
    std::unique_ptr<ProblemSolution> solve(const Graph& graph) override; 

};

#endif // MST_SOLVER_H 