#include "Graph.h"
#include <iostream>

// Constructor that initializes the graph with the given number of vertices
// The adjacency list is resized to accomodate the number of vertices
Graph::Graph(int vertices, const std::string& name) : numVertices(vertices), adjacencyList(vertices), graphName(name) {}

// Method to add an edge to graph's adjacency list
void Graph::addEdge(int source, int destination, int weight) {
    // add the edge from source to destination 
    adjacencyList[source].push_back({source, destination, weight});
    // add the edge to source (for undirected graph)
    adjacencyList[destination].push_back({destination, source, weight}); // Aggiungi l'arco nell'altra direzione per un grafo non orientato
}

// method to get the name of the graph 
std::string Graph::getGraphName() const {

    return graphName;
}

// method to set the name of the graph 
void Graph::setGraphName(const std::string& name) {

    graphName = name; 
}

// method to print the graph's adjacency list
void Graph::printGraph() const {

    for (int i = 0; i < numVertices - 1; i++) {

        std::cout << "Vertex " << i << ":\n";

        // iterate over each edge in the vertex's adjacency list  
        for (const auto& edge : adjacencyList[i]) {

            // print edge details if it's a forward edge 
            if (i < edge.destination) {
                std::cout << " -> (" << edge.destination << ", weight: " << edge.weight << ")\n"; 
            }
        }
        std::cout << std::endl;
    }
}

// method to get the adjacency list of specific vertex
const std::vector<Edge>& Graph::getAdjacencyList(int vertex) const {

    return adjacencyList[vertex];
}

// method to get the number of vertices in the graph
int Graph::getNumVertices() const {

    return numVertices;

}