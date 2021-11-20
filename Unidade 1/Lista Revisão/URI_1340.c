#include <stdio.h>
#include <stdlib.h>

// NÃO FINALIZADO

// gcc URI_1340.c -o URI_1340 && ./URI_1340

void removeValue(int * vector, int value, int size){
	int i, j;
	for (i = 0; i < size; i++) {
		if (vector[i] == value) break;
	}
	if (i > size) return;
	for(j = i; j < size - 1; j++){
		printf("%d <- %d\n", vector[j], vector[j + 1]);
		vector[j] = vector[j + 1];
	}
}

int main(){
	int i;
	int v[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	removeValue(v, 1, 8);
	for (i = 0; i < 7; i++) printf("%d ", v[i]);
	printf("\n");

	return 0;

	int n, op, value, size;
	int * vector = NULL;

	while (scanf("%d", &n) != EOF) {
		size = 0;
		while(n--){

			scanf("%d %d", &op, &value);
			if (op == 1){
				size++;
				vector = (int *) realloc(vector, size*sizeof(int));
				vector[size - 1] = value;
			}
			else if (op == 2){
				
			}
		}
	}

	if (vector != NULL) free(vector);

	return 0;
}