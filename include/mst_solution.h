#ifndef MST_SOLUTION_H 
#define MST_SOLUTION_H

#include "problem_solution.h"
#include "graph.h"
#include <vector>

// MSTSolution class definition
// Inherits from ProblemSolution and represent solution for MST problem
class MSTSolution : public ProblemSolution {

private: 
    std::vector<Edge> mstEdges;             // stores the edges part of MST
    int totalWeight;                        // total weight of the MST

public: 
    // Constructor that initializes mstEdges and totalWeight members
    MSTSolution(const std::vector<Edge>& edges, int weight);

    // output method overrides the pure virtual method from ProblemSolution base class 
    // it prints MST details (edges and total weight) to provided output stream
     std::ostream& output(std::ostream& os) const override;

};



#endif // MST_SOLUTION_H