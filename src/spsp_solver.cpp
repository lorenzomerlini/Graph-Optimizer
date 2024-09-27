#include "spsp_solver.h"
#include "spsp_solution.h"

/* SPSPSolver is an implementation of ProblemSolver interface.
It's used to solve the Single-Pair Shortest Path (SPSP) problem. 
This method takes a const reference to a Graph object as an argument
and returns a pointer to ProblemSolution object (SPSPSolver object)
*/

std::unique_ptr<ProblemSolution> SPSPSolver::solve(const Graph& graph) {

    int start, end;                                         // start / end vertices
    int numVertices = graph.getNumVertices();               // get the total number of vertices 

    // input for start vertex with validation 
    do {
        std::cout << "\nInsert start vertex (0 to " << numVertices - 1 << "): "; 
        std::cin >> start; 
        if (start < 0 || start >= numVertices) {

            std::cout << "\nInvalid start vertex! Please enter a valid vertex within the range.\n"; 
        }
    } while (start < 0 || start >= numVertices);                                    
    
    do {
        std::cout << "\nInsert end vertex (0 to " << numVertices - 1 << "): "; 
        std::cin >> end; 
        if (end < 0 || end >= numVertices) {
            std::cout << "\nInvalid end vertex! Please enter a valid vertex within the range.\n"; 
        }
    } while (end < 0 || end >= numVertices); 

    const int INF = std::numeric_limits<int>::max();        // define infinity value (INF)
    std::vector<int> dist(graph.getNumVertices(), INF);     // initialize distance vector with INF
    std::vector<int> prev(graph.getNumVertices(), -1);      // initialize predecessor vector to store previous vertex in shortest path

    using PII = std::pair<int, int>;                        // alias for a pair of integers (distance, vertex)

    // priority queue to store pairs of (distance, vertex). Smallest distance = highest priority
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;  
    
    dist[start] = 0;                                        
    pq.push({0, start});                                    // push start vertex to pq with 0 distance

    // process pq until it's empty
    while (!pq.empty()) {

        int current = pq.top().second;                      // extract vertex with min distance
        int currentDist = pq.top().first;                   // extract distance of current vertex 
        pq.pop();                                           // remove it from pq

        // skip if current distance > already known distance
        if (currentDist > dist[current]) continue; 

        // iterate throug neighbors of current vertex ~ method from Graph class
        for (const Edge& edge : graph.getAdjacencyList(current)) { 

            int neighbor = edge.destination;                // neighbor vertex
            int newDist = currentDist + edge.weight;        // new distance to neighbor vertex

            // if found shorter path
            if (newDist < dist[neighbor]) {

                dist[neighbor] = newDist;                   // update shortest distance to neighbor
                prev[neighbor] = current;                   // set current vertex as predecessor of neighbor
                pq.push({newDist, neighbor});               // push neighbor in pq (with upt distance)
            }
        }
    }

    // build shortest path by backtracking from end vertex 
    std::vector<int> path; 
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);                                 // add each vertex encountered as backtracking 
    }
    std::reverse(path.begin(), path.end());                 // reverse the path to get correct order from start to end

    // if path is one vertex & is not start vertex = no path exist
    if (path.size() == 1 && path[0] != start) {
        path.clear();                                      
    }

    // return a new SPSPSolution object containig path and shortest distance to end vertex
    return std::make_unique<SPSPSolution>(path, dist[end]); 
}