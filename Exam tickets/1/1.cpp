#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int size;
	int **matrix = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) matrix[i] = (int)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", matrix[i][j]);
		}
	}
}
