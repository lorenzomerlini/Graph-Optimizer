#ifndef PROBLEM_SOLUTION_H 
#define PROBLEM_SOLUTION_H

#include "Graph.h"
#include <iostream>

// Abstract base class for problem solutions. 
// Defines the interface for representing solution to graph-related problems
class ProblemSolution {

public: 

    // pure virtual function to output the solution
    // takes a reference to ostream obj as input
    // subclasses must implement this function to define the output
    virtual std::ostream& output(std::ostream& os) const = 0; 

    // virtual destructor to proper cleanup of resources
    // declared as virtual for derived classes 
    virtual ~ProblemSolution() {} 
};

#endif // PROBLEM_SOLUTION_H