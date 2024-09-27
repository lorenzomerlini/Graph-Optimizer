#ifndef GRAPH_H 
#define GRAPH_H

#include <vector>
#include <string>

// Edge struct represents an edge in the graph
struct Edge {

    int source;         // source vertex  
    int destination;    // destination vertex   
    int weight;         // weight of the edge 

    // operator overloading for the > operator
    // used to compare two edges based on their weight
    bool operator>(const Edge& other) const {

        return weight > other.weight; 
    }
};

// Graph class definition
class Graph {

private: 
    int numVertices;                            // number of vertices in the graph
    // adjacency list representation of the graph
    std::vector<std::vector<Edge>> adjacencyList;

    std::string graphName;                      // name of the graph

public:
    // Constructor to initialize the graph with a specified number of vertices
    Graph(int vertices, const std::string& name);

    // method to add an edge to the graph
    void addEdge(int source, int destination, int weight); 

    // method to print the graph's adjacency list
    void printGraph() const;

    // method to get the adjacency list of a specific vertex
    const std::vector<Edge>& getAdjacencyList(int vertex) const; 

    // method to get the number of vertices in the graph
    int getNumVertices() const;         

    // method to get the name of the graph
    std::string getGraphName() const; 
    
    // method to set the name of the graph
    void setGraphName(const std::string& name); 
}; 
// Function declaration to import graph from external source
bool ImportGraph(Graph& graph); 

#endif // GRAPH_H