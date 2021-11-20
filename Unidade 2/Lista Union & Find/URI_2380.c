#include <stdio.h>

// gcc URI_2380.c -o URI_2380 && ./URI_2380

#define MAX 100000

typedef struct set {
	int rank[MAX], parent[MAX];
} Set;

Set set;

void makeSet(){
	int i;
	for (i = 0; i < MAX; i++){
		set.parent[i] = i;
		set.rank[i] = 0;
	}
}

int Find(int x){
	if (x != set.parent[x])
		set.parent[x] = Find(set.parent[x]);
	return set.parent[x];
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);

	if (set.rank[x] > set.rank[y])
		set.parent[y] = x;
	else
		set.parent[x] = y;
	
	if (set.rank[x] == set.rank[y])
		set.rank[y]++;

}


int main(){
	int N, B, code1, code2;
	char opr;

	scanf("%d %d%*c", &B, &N);

	makeSet();

	while (N--){
		scanf("%c %d %d%*c", &opr, &code1, &code2);
		
		switch (opr){
			case 'C':
				if (Find(code1) == Find(code2))
					printf("S\n");
				else 
					printf("N\n");
				break;
			case 'F':
				Union(code1, code2);
				break;
		}
	}

    return 0;
}

