#ifndef SSSP_SOLVER_H 
#define SSSP_SOLVER_H

#include "problem_solver.h"                     // base class for problem solvers
#include "sssp_solution.h"                      // solution class specific to SSSP
#include "graph.h"                              // Graph class 

#include <vector>
#include <queue>
#include <limits>

class SSSPSolution;                             // forward declaration of SSSPSolution class 

// SSSPSolver class inherits from ProblemSolver and implements solve method for SSSP
class SSSPSolver : public ProblemSolver {

public: 
    // solve function overrides pure virtual method from ProblemSolver base class
    // it takes a const reference to Graph obj
    std::unique_ptr<ProblemSolution> solve(const Graph& graph) override; 

}; 

#endif // SSSP_SOLVER_H