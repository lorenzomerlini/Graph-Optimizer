#ifndef PROBLEM_SOLVER_H 
#define PROBLEM_SOLVER_H

#include "graph.h"
#include "problem_solution.h"
#include <memory>

// abstract base class for problem solvers. 
// defines the interface for solving graph problems
class ProblemSolver {

public:
    // pure virtual function to solve graph optimization problems 
    // takes a const reference to a Graph obj as input 
    // subclasses must implement this function to define specific problem solution
    virtual std::unique_ptr<ProblemSolution> solve(const Graph& graph) = 0;

    // virtual destructor to ensure cleanup of resources 
    // declared as virtual for derived classes
    virtual ~ProblemSolver() {} 
}; 

#endif // PROBLEM_SOLVER_H 