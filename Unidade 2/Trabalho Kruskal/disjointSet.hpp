#ifndef __DISJOINT_SET_HPP__
#define __DISJOINT_SET_HPP__

#include <iostream>
#include <vector>

/**
 * @class DisjointSet: classe de um conjunto disjunto

 * @attr (vector<int>) parents: vetor contendo os representantes
 * @attr (vector<int>) ranks: vetor contendo os ranks
 * @attr (int) size: quantidade de elementos
*/
class DisjointSet{
	private:
	// Private Attributes
		std::vector<int> parents, ranks;
		int size;
	public:
	// Constructors
		DisjointSet();
		DisjointSet(int size);
	// Basic functions
		void join(int child1, int child2);
		int find(int child);
		void print();
	// Getters and Setters
		int getSize();
};

#endif // __DISJOINT_SET_HPP__