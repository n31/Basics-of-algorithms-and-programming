#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>


int main() {
	srand(time(0));
	int n;
	scanf("%d", &n);
	int **arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 10;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	int i = n - 1;
	while (i >= 0) {
		int j = n - 1;
		while (j >= 0) {
				if (i == j) break;
				int tmp = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = tmp;
			j--;
		}
		i--;
	}

	printf("\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
