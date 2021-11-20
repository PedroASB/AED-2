#include "union_find.hpp"

void makeSet(DisjointSet set){
	int i;
	for(i = 0; i < MAX; i++){
		set.parent[i] = i;
		set.rank[i] = 0;
	}
}

int Find(DisjointSet set, int x){
	if (x != set.parent[x])
		set.parent[x] = Find(set, set.parent[x]);
	return set.parent[x];
}

void Union(DisjointSet set, int x, int y){
	x = Find(set, x);
	y = Find(set, y);

	if (set.rank[x] > set.rank[y])
		set.parent[y] = x;
	else {
		set.parent[x] = y;
		if (set.rank[x] == set.rank[y])
			set.rank[y]++;
	}
}