#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>

typedef int Vertex;
typedef int Weight;

class Graph {
	private:
	// Private Attributes
		int qtt_vertices;
		std::vector< std::vector<std::pair<Weight, Vertex>> > adjacencyLists;

	public:
	// Constructor and Destructor
		Graph(int qtt_vertices);
		
	// Basic Functions
		void addEdge(int source, int destination, int weight);

	// Dijkstra Algorithm
    int dijkstraAlgorithm(
    	int source, int destination, 
    	std::vector<int> & distance,std::vector<int> & parents
    );
};


#endif // __GRAPH_HPP__
