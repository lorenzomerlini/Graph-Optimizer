#include "Graph.h"
#include "graph_utils.h" 
#include <iostream>
#include <string>

using namespace std; 

int main() {
 
    Graph currentGraph(0, "");                                              // Initialize an empty graph             
    std::unique_ptr<ProblemSolution> solution = nullptr;                                // Initialize an empty solution
    int choice;
    cout << "Welcome to " << endl;                                                         // Variable to store user choice 
    cout << R"(
 _____                 _       _____       _   _           _              
|  __ \               | |     |  _  |     | | (_)         (_)             
| |  \/_ __ __ _ _ __ | |__   | | | |_ __ | |_ _ _ __ ___  _ _______ _ __ 
| | __| '__/ _` | '_ \| '_ \  | | | | '_ \| __| | '_ ` _ \| |_  / _ \ '__|
| |_\ \ | | (_| | |_) | | | | \ \_/ / |_) | |_| | | | | | | |/ /  __/ |   
 \____/_|  \__,_| .__/|_| |_|  \___/| .__/ \__|_|_| |_| |_|_/___\___|_|   
                | |                 | |                                   
                |_|                 |_|                                   
)" << endl; 

    do {
 
        // Show menu 
        cout << "\nSelect one option: \n"; 
        cout << "1. Import graph from txt file\n"; 
        cout << "2. Select problem resolution for the graph\n"; 
        cout << "3. Print current solution on screen\n"; 
        cout << "4. Export solution to txt file\n"; 
        cout << "5. Close application\n\n"; 
        cout << "Input your choice: "; 

        if(!(cin >> choice)) {
            
            cout << "\nInvalid input. Please enter a number. \n"; 
            cin.clear();                                                // clear error flag 
            cin.ignore(10000, '\n');                                    // discard invalid input  
            continue; 
        }

        switch (choice) {
            case 1: 
                
                if (ImportGraph(currentGraph, solution)) {                        // call ImportGraph function
                    cout << "\nGraph imported successfully.\n"; 

                } else {
                    cout << "\nFailed to import graph.\n"; 
                }
                break; 
            case 2:
                ProblemsList(currentGraph, solution);                   // call ProblemsList function 
                break; 
            case 3: {
                 
                PrintSolution(solution, currentGraph.getGraphName());   // call PrintSolution function
                break;
            }
            case 4:

                PrintToFile(solution, currentGraph.getGraphName());     // call PrintToFile function 
                break; 
            case 5: 
                cout << "\n\nClosing application...\n";
                break;
            default:
                break; 
                cout << "\nInput not valid, try again.\n"; 
        }
    } while (choice != 5);      // repeat cycle until user choose to exit (5)

    return 0; 
}