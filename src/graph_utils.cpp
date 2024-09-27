#include "Graph.h"
#include "mst_solver.h"
#include "mst_solution.h"
#include "spsp_solver.h"
#include "spsp_solution.h"
#include "sssp_solver.h"
#include "sssp_solution.h"
#include "apsp_solution.h"
#include "apsp_solver.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* ImportGraph is a function to import a graph from a txt file. 
It takes a reference to a Graph object as an argument (where the graph will be stored). 
It returns a boolean value (true/false) indicating if the import was successful. 
*/
bool ImportGraph(Graph& currentGraph, std::unique_ptr<ProblemSolution>& solution) {

    if (solution) {

        solution.reset();       // deallocate precedent solution
    }
    
    std::string filename;                                       // variable to hold the name of the file 

    std::cout << "Enter a valid filename: "; 
    std::cin >> filename; 

    std::string filepath = "instances/" + filename + ".txt";    // path of the file (search in "istances" folder) 

    std::ifstream myfile (filepath);                            // open the file in read mode 

    if (myfile.is_open()) {                                     // check if the file is successfully opened

        std::string line;                                       // line: holds the current line read from the text

        int vertices = 0, edges = 0;                            // variables to hold vertices and edges
        char graphName[256];                                    // variable to to hold the name of the graph
        std::getline(myfile, line);
        
        sscanf(line.c_str(), "NAME: %255s", graphName);         // read the name of the graph - first line
        std::string graphNameStr(graphName); 
        

        std::getline(myfile, line); 
        sscanf(line.c_str(), "n: %d", &vertices);               // read the number of vertices - second line 

        std::getline(myfile, line); 
        sscanf(line.c_str(), "m: %d", &edges);                  // read the number of edges - third line

        currentGraph = Graph(vertices, graphNameStr);                         // constructor of Graph class is called with the number of vertices

        int source, destination, weight; 

        while (myfile >> source >> destination >> weight) {     // read the source, destination and weight of each edge

            currentGraph.addEdge(source, destination, weight);  // add the edge to the graph 
        }

        myfile.close();                                         // close the file 
         
        return true;

    } else {

        std::cout << "Unable to open the file." << std::endl; 
        return false; 

    }
}

/* ProblemsList is a function to select the problem resolution for the graph.
It takes a reference to a Graph object as an argument (where the graph is stored), called "currentGraph", and a reference to a
ProblemSolution object (where the solution will be stored), called "solution". */

void ProblemsList(const Graph& currentGraph, std::unique_ptr<ProblemSolution>& solution) {

    int choice;                                                 // variable to store user choice 

    cout << "\nSelect one problem resolution: \n";
    cout << "1. Minimum Spanning Tree\n"; 
    cout << "2. Single-Pair Shortest Path\n";
    cout << "3. Single-Source Shortest Path\n";
    cout << "4. All-Pairs Shortest Path\n"; 
    cout << "5. Exit\n";

    cout << "Enter your choice: "; 

    if (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number. \n"; 
        cin.clear();                                            // clear error flag 
        cin.ignore(10000, '\n');                                // discard invalid input 
        return; 
    }

    switch (choice) {
        case 1: {
            // Minimum Spanning Tree
            MSTSolver mstSolver;                                 
            solution = mstSolver.solve(currentGraph);           // store in solution the result of mstSolver
            cout << "\nGraph problem solved!\n"; 
            break;
        }
        case 2: {
            // Single-Pair Shortest Path
            SPSPSolver spspSolver;
            solution = spspSolver.solve(currentGraph);          // store in solution the result of spspSolver 
            cout << "\nGraph problem solved!\n";
            break;
        }
        case 3: {
            // Single-Source Shortest Path
            SSSPSolver ssspSolver; 
            solution = ssspSolver.solve(currentGraph);          // store in solution the result of ssspSolver 
            cout << "\nGraph problem solved!\n";
            break;
        }
        case 4: {
            // All-Pairs Shortest Path 
            APSPSolver apspSolver; 
            solution = apspSolver.solve(currentGraph);          // store in solution the result of apspSolver
            cout << "\nGraph problem solved!\n";
            break; 
        }
        case 5: 
            // Close ProblemsList 
            break;  
    }       
}

/* PrintSolution is a function to print the solution on screen.
It takes a reference to a ProblemSolution object (solution) and a string (graphName) as arguments.*/
void PrintSolution(const std::unique_ptr<ProblemSolution>& solution, const std::string& graphName) {
  
    if (solution != nullptr) {                                      // if solution is not null (there is a solution)
                                            
        std::cout << "\nSolution found for " << graphName << "\n\n"; 
        solution->output(std::cout);                                // call output function from the ProblemSolution class
    
    } else {

        std::cout << "\nNo solution stored yet. Solve a problem first.\n" << std::endl; 
    }
}

/* PrintToFile is a function to print the solution on a txt file. 
It takes a reference to a ProblemSolution object (solution) and a string (graphName) as arguments.*/
void PrintToFile(const std::unique_ptr<ProblemSolution>& solution, const std::string& graphName) {

    if (solution == nullptr) {                                      // if solution is null (there is no solution)

        std::cout << "\nNo solution found yet! Resolve a problem first.\n" << std::endl;
         
    } else {

        std::string baseFilename;                                   // variable to store the base filename
        std::cout << "\nEnter the name of the file to save the solution: \n";  
        cin >> baseFilename;

        std::string filename = baseFilename + ".txt";               // add .txt extension to the base filename

        std::ofstream outFile(filename);                            // open the file in write mode
        if (!outFile.is_open()) {

            std::cerr << "\nFailed to open file: " << filename << "\n"; 
             
        }

        outFile << "\nGraph Name: " << graphName << "\n\n";           // write the graph name on the file 
        solution->output(outFile);                                  // call output function from the ProblemSolution class 
        outFile.close();                                            // close the file 
        std::cout << "\nSolution saved to " << filename << "\n"; 
         
    }
}