#ifndef __UNION_FIND_HPP__
#define __UNION-FIND_HPP__

#include <iostream>
#define MAX 1000

typedef struct disjointSet {
	int rank[MAX];
	int parent[MAX];
} DisjointSet;

#endif // __UNION_FIND_HPP__