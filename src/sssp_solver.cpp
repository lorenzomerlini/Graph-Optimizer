#include "sssp_solver.h"
#include "sssp_solution.h"

/* SSSPSolver is an implementation of the problem solver interface.
 * It is used to solve the Single Source Shortest Path problem.
 * It takes a const reference to a Graph object as an argument and returns a 
 * pointer to a ProblemSolution object (specifically a SSSPSolution object).*/
std::unique_ptr<ProblemSolution> SSSPSolver::solve(const Graph& graph) {

    int start;                                                          // starting vertex 
    std::cout << "Insert starting vertex: "; 
    std::cin >> start;

    const int INF = std::numeric_limits<int>::max();                    // constant infinity value
    std::vector<int> dist(graph.getNumVertices(), INF);                 // vector to store the shortest distance from start vertex to each vertex
                                                                        // all distances set to INF

    // declare a priority queue (pq) to store pairs of (distance, vertex). 
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
     
    dist[start] = 0;                                                    // distance start vertex at 0 
    pq.push({0, start});                                                // push starting vertex into pq

    while (!pq.empty()) {                                               // main loop ~ continue until pq is empty

        // extract the vertex with min distance from pq
        int current = pq.top().second;                                  // current vertex 
        int currentDist = pq.top().first;                               // distance associated with current vertex 
        pq.pop();                                                       // pop the top element from pq 

        // if new distance is greater than recorded shortest distance, skip this vertex
        if (currentDist > dist[current]) continue; 

        // iterate through neighbors of current vertex
        for (const Edge& edge : graph.getAdjacencyList(current)) {
            int neighbor = edge.destination;                            // get the neighbor vertex
            int newDist = currentDist + edge.weight;                    // potential shortest distance to the neighbor

            // if new distance is shorter
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;                               // update shortest distance
                pq.push({newDist, neighbor});                           // push neighbor in pq
            }
        }
    }
    // return a new SSSPSolution object
    return std::make_unique<SSSPSolution>(dist); 
}