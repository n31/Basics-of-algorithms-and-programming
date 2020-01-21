#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

int tratioo(int **arr, int i, int j, int n) {
	if (i == j) return tratioo(arr, i - 1, n - 1, n);
	if (i < 0) return 0;
	int tmp = arr[i][j];
	arr[i][j] = arr[j][i];
	arr[j][i] = tmp;
	return tratioo(arr, i, j - 1, n);
}

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
	tratioo(arr, n - 1, n - 1, n);
	/*for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (j == i) break;
			int tmp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tmp;
		}
	}*/
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}