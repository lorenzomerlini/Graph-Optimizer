#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "graph.h"
#include "mst_solution.h"
#include <memory>

// function to import a graph from external source into currentGraph obj
bool ImportGraph(Graph& currentGraph, std::unique_ptr<ProblemSolution>& solution);

// function that takes a graph and reference to a ProblemSolution pointer
// implements the user's possibility to solve an optimization problem on the graph 
void ProblemsList(const Graph& currentGraph, std::unique_ptr<ProblemSolution>& solution);

// function to print the solution of the current graph problem on the console
void PrintSolution(const std::unique_ptr<ProblemSolution>& solution, const std::string& graphName);

// function to print the solution of the current graph problem on external file
void PrintToFile(const std::unique_ptr<ProblemSolution>& solution, const std::string& graphName); 

#endif // GRAPH_UTILS_H