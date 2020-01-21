#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

int summy(int **arr, int i, int j, int size, int count, int sum) {
    if (count > 4) return sum;
    if (i == j) {
        if (i == size - 1) return sum;
        printf("\n");
        return summy(arr, i + 1, 0, size, count, sum);
    }
    printf("%d ", arr[i][j]);
    return (arr[i][j] % 2 == 0) ? summy(arr, i, j + 1, size, count + 1, sum += arr[i][j]) : summy(arr, i, j + 1, size, count, sum);
}

int main() {
    srand(time(0));
    int size;
    scanf("%d", &size);
    int **arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        arr[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            arr[i][j] = rand() % 10;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    printf("\n%d", summy(arr, 0, 0, size, 0, 0));
    return 0;
}