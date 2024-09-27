#ifndef SPSP_SOLVER_H 
#define SPSP_SOLVER_H

#include "problem_solver.h"
#include "graph.h"
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>


class SPSPSolution;                 // forward declaration of the SPSPSolution class

// SPSPSolver class definition
// Inherits from ProblemSolver and implements solve method for SPSP problem
class SPSPSolver : public ProblemSolver {

public: 

    // the solve function overrides the pure virtual method from ProblemSolver base class
    // takes const reference to a Graph obj
    std::unique_ptr<ProblemSolution> solve(const Graph& graph) override; 

};

#endif // SPSP_SOLVER_H 