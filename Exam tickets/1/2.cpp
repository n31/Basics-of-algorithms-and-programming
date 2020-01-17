#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
	int size;
       	scanf("%d", &size);
	char **arr = (char**)malloc(size * sizeof(char*));
	for (int i = 0; i < size; i++) {
		int j = 1, c;
		while ((c = getchar()) != EOF && c != '\n') {
			j++;
			arr[i] = (char*)realloc(arr[i], j);
			if (arr[i] != NULL) {
				arr[i][j-2] = c;
				arr[i][j-1] = '\0';
			}
		}
	}

	printf("\n\n\nEND.\n\n\n");
	return 0;
}
