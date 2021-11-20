#include "graph.hpp"
#include <iostream>
#include <queue>

typedef std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater <std::pair<int, int>>> Heap;


Graph::Graph(int qtt_vertices){
	if (qtt_vertices < 1) return;

	this->qtt_vertices = qtt_vertices;
	this->adjacencyLists.resize(qtt_vertices);
}

void Graph::addEdge(int source, int destination, int weight){
	if (source < 0 || destination < 0/* || weight < 0*/) return;

	this->adjacencyLists[source].push_back({weight, destination});
}

int Graph::dijsktraAlgorithm(
	int source, int destination, 
	std::vector<int> & distance, std::vector<int> & parents)
{
	Heap minHeap;
	int parent_vertex, parent_weight;
	int current_vertex, current_weight;

	minHeap.push({0, source});
	distance[source] = 0;

	while(!minHeap.empty()){
		current_weight = minHeap.top().first;
		current_vertex = minHeap.top().second;
		minHeap.pop();

		if (current_vertex == destination) break;

		if (parents[current_vertex] == 1) continue;
		else parents[current_vertex] = 1;

		for(auto vertex: this->adjacencyLists[current_vertex]){
			parent_weight = vertex.first;
			parent_vertex = vertex.second;

			if (current_weight + parent_weight < distance[parent_vertex]){
				distance[parent_vertex] = current_weight + parent_weight;
				minHeap.push({distance[parent_vertex], parent_vertex});
			}
		}
	}
	
	return distance[destination];
}