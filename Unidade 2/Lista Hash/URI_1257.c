#include <stdio.h>

// gcc URI_1257.c -o URI_1257 && ./URI_1257

int main(){
	int N, L;
	int hash, index, line;
	char str[55];
	
	scanf("%d", &N);

	while (N--){
		scanf("%d", &L);

		hash = 0;
		for (line = 0; line < L; line++){
			scanf("%s", str);

			index = 0;
			while (str[index] != '\0'){
				hash += (str[index] - 'A') + line + index;
				index++;
			}

		}

		printf("%d\n", hash);
	}

	return 0;
}