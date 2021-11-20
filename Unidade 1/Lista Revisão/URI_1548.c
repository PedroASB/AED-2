#include <stdio.h>
#include <stdlib.h>

// gcc URI_1548.c -o URI_1548 && ./URI_1548

void shellSort(int v[], int size){
	int i, j, value;
	int h = 1;

	while (h < size){
		h = 3*h + 1;
	}
	
	while (h > 0){
		for (i = h; i < size; i++){
			value = v[i];
			j = i;
			while (j > (h - 1) && value > v[j - h]){
				v[j] = v[j - h];
				j = j - h;
			}
			v[j] = value;
		}
		h = h / 3;
	}
}

int compareArrays(int v1[], int v2[], int size){
	int i, swaps = 0;
	for (i = 0; i < size; i++){
		if (v1[i] != v2[i]) swaps++;
	}
	return swaps;
}

int main(){
	int N, M, i, swaps, v[1000], tmp[1000];
	scanf("%d", &N);

	while (N--){
		scanf("%d", &M);
		for (i = 0; i < M; i++){
			scanf("%d", &v[i]);
			tmp[i] = v[i];
		}
		shellSort(v, M);
		swaps = compareArrays(tmp, v, M);
		printf("%d\n", M - swaps);
	}

	return 0;
}