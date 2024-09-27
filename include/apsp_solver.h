#ifndef ASPS_SOLVER_H 
#define APSP_SOLVER_H 

#include "problem_solver.h"
#include "apsp_solution.h"
#include "graph.h"
#include <vector>
#include <limits> 

class APSPSolution;                 // forward declaration of the APSPSolution


/* APSPSolver class definition 
Inherits from ProblemSolver and implements the solve method for APSP problems
*/
class APSPSolver : public ProblemSolver {

public: 
    // solve function overrides the pure virtual method from ProblemSolver base class
    // takes a const reference to a Graph obj 
    std::unique_ptr<ProblemSolution> solve(const Graph& graph) override; 

}; 

#endif // APSP_SOLVER_H