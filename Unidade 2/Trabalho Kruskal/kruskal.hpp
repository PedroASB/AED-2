#ifndef __KRUSKAL_HPP__
#define __KRUSKAL_HPP__

#include <vector>

typedef int Weight; // Peso de uma aresta
typedef int Vertex; // Vértice
typedef std::pair<Weight, std::pair<Vertex, Vertex>> Edge; // Aresta

/**
 * @class Graph: classe de um grafo

 * @attr (vector<Edge>) listEdge: vetor contendo as arestas
 * @attr (int) size: quantidade de arestas
 * @attr (int) totalWeight: peso total do grafo
 * @attr (int) qtt_vertices: quantidade de vértices
*/
class Graph{
	private:
	// Private Attributes
		std::vector<Edge> listEdge;
		int size;
		int totalWeight;
		int qtt_vertices;
	// Auxiliary Functions
		void printEdge(Edge edge);
		Edge createEdge(int weight, int vertex1, int vertex2);
	public:
	// Constructors
		Graph();
		Graph(int qtt_vertices);
	// Basic Functions
		void insert(int weight, int vertex1, int vertex2);
		void print();
	// Kruskal's Algorithm
		Graph kruskal();
	// Getters and Setters
		int getWeight();
};

#endif // __KRUSKAL_HPP__