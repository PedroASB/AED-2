#include "kruskal.hpp"
#include "disjointSet.hpp"

#include <utility>
#include <algorithm>

/**
 * Função construtora (sem parâmetro)
 *
 */
Graph::Graph(){
	this->qtt_vertices = this->size = this->totalWeight = 0;
}

/**
 * Função construtora (com parâmetro)
 *
 * @param (int) qtt_vertices: quantidade de vértices
 */
Graph::Graph(int qtt_vertices){
	this->size = this->totalWeight = 0;
	this->qtt_vertices = qtt_vertices;
}

/**
 * Cria uma nova aresta
 *
 * @param (int) weight: peso da aresta
 * @param (int) vertex1: vértice 1
 * @param (int) vertex2: vértice 2
 * @return (Edge) aresta formada
 */
Edge Graph::createEdge(int weight, int vertex1, int vertex2){
	return {weight, {vertex1, vertex2}};
}

/**
 * Insere uma nova aresta no grafo
 *
 * @param (int) weight: peso da aresta
 * @param (int) vertex1: vértice 1
 * @param (int) vertex2: vértice 2
 */
void Graph::insert(int weight, int vertex1, int vertex2){
	Edge edge = this->createEdge(weight, vertex1, vertex2);
	this->listEdge.push_back(edge);
	this->size++;
	this->totalWeight += weight;
}

/**
 * Imprime o peso e os dois vértices de uma aresta
 *
 * @param (Edge) edge: aresta
 */
void Graph::printEdge(Edge edge){
	using namespace std;
	cout << "W: " << edge.first;
	cout << " | " << edge.second.first << " - " << edge.second.second;
}

/**
 * Imprime a lista de arestas de um grafo
 *
 */
void Graph::print(){
	for(auto edge: this->listEdge){
		printEdge(edge);
		std::cout << std::endl;
	}
}

/**
 * Realiza o Algoritmo de Kruskal para obter uma 
 * árvore geradora mínima do grafo
 *
 * @return (Graph) árvore geradora mínima formada
 */
Graph Graph::kruskal(){
	Graph minimumGraph(this->qtt_vertices);
	DisjointSet set(this->qtt_vertices);
	int current_weight, current_vertex1, current_vertex2;

	sort(this->listEdge.begin(), this->listEdge.end());

	for(auto edge: this->listEdge){
		current_weight = edge.first;
		current_vertex1 = edge.second.first;
		current_vertex2 = edge.second.second;
		
		if(set.find(current_vertex1) != set.find(current_vertex2)){
			set.join(current_vertex1, current_vertex2);
			minimumGraph.insert(current_weight, 
									current_vertex1, current_vertex2);
		}

	}
	
	return minimumGraph;
}

/**
 * Retorna o peso total do grafo
 *
 * @return (int) peso total do grafo
 */
int Graph::getWeight(){
	return this->totalWeight;
}