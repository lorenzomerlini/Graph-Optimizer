#include "apsp_solution.h"
#include <iostream>
#include <limits>

// initialize the APSPSolution obj with the provided distance matrix 
APSPSolution::APSPSolution(const std::vector<std::vector<int>>& dist) : dist(dist) {}

// output method: outputs the distance matrix to the provided ostream object
// each element in the matrix represent the shortest distance between 
//a pair of vertices
std::ostream& APSPSolution::output(std::ostream& os) const {

    os << "All Pairs Shortest Path:\n";
    os << "The following matrix shows the shortest distances between every pair of vertices \n";

    const int INF = std::numeric_limits<int>::max();        // constant infinite

    for (size_t i = 0; i < dist.size(); ++i) {

        for (size_t j = 0; j < dist[i].size(); ++j) {

            if (dist[i][j] == INF) {                        // if distance is infinite no path exist between vertices

                os << "INF "; 
            } else {

                os << dist[i][j] << "\t"; 
            }
        }
        os << "\n"; 
    }
    return os;
}