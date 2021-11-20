#include <stdio.h>
#include <stdlib.h>

// gcc URI_1259.c -o URI_1259 && ./URI_1259

typedef struct vector {
	int size;
	int * data;
} Vector;

void shellSort(Vector v, int sort){
	int i, j, value;
	int h = 1;

	while (h < v.size){
		h = 3*h + 1;
	}
	
	while (h > 0){
		for (i = h; i < v.size; i++){
			
			value = v.data[i];
			j = i;

			if (sort == 1){ // Ordem crescente
				while (j > (h - 1) && value <= v.data[j - h]){
					v.data[j] = v.data[j - h];
					j = j - h;
				}
			}
			else if (sort == 2){ // Ordem decrescente
				while (j > (h - 1) && value > v.data[j - h]){
					v.data[j] = v.data[j - h];
					j = j - h;
				}
			}
			else return;

			v.data[j] = value;
		}
		h = h / 3;
	}
}

void printVector(Vector v){
	int i;
	for (i = 0; i < v.size; i++){
		printf("%d\n", v.data[i]);
	}
}

int main(){
	int i, N, value; 
	Vector odd, even;

	odd.data = (int *) calloc(1, sizeof(int));
	even.data = (int *) calloc(1, sizeof(int));
	odd.size = even.size = 0;

	scanf("%d", &N);

	while (N--){
		scanf("%d", &value);
		if (value % 2 == 0){
			even.size++;
			even.data = (int *) realloc(even.data, even.size * sizeof(int));
			even.data[even.size - 1] = value;
		} 
		else {
			odd.size++;
			odd.data = (int *) realloc(odd.data, odd.size * sizeof(int));
			odd.data[odd.size - 1] = value;
		}
	}

	shellSort(even, 1);
	shellSort(odd, 2);

	printVector(even);
	printVector(odd);

	free(odd.data);
	free(even.data);

	return 0;
}