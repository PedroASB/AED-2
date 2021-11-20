#include <iostream>
#include <vector>
#include "graph.hpp"

#define MAX_SIZE 110
#define INF 100000000

using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
		
	Graph plane(0);
	Graph bus(0);
	int qtt_vertices, qtt_edges;
	int from, to, type, weight;
	vector<int> distance(MAX_SIZE);
	vector<int> parent(MAX_SIZE);
	int source, destination;
	int distance_bus, distance_plane;

	while(cin >> qtt_vertices >> qtt_edges){
		distance_bus = distance_plane = 0;

		plane = Graph(qtt_vertices);
		bus = Graph(qtt_vertices);

		source = 0;
		destination = qtt_vertices - 1;

		while (qtt_edges--){
		cin >> from >> to >> type >> weight;
		from--;
		to--;
		if (type == 0)
			bus.addEdge(from, to, weight);
		else 
			plane.addEdge(from, to, weight);
		}

		fill_n(distance.begin(), qtt_vertices, INF);
		fill_n(parent.begin(), qtt_vertices, 0);

		distance_bus = bus.dijsktraAlgorithm(source, destination, distance, parent);

		fill_n(distance.begin(), qtt_vertices, INF);
		fill_n(parent.begin(), qtt_vertices, 0);

		distance_plane = plane.dijsktraAlgorithm(source, destination, distance, parent);

		cout << min(distance_bus, distance_plane) << endl;
	}
	
	return 0;
} 