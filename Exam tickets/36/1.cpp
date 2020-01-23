#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void reverse(int *arr, int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main() {
    int nstr, nstb;
    scanf("%d %d", &nstr, &nstb);
    int **arr = (int**)malloc(nstr * sizeof(int*));
    for (int i = 0; i < nstr; i++) {
        arr[i] = (int*)malloc(nstb * sizeof(int));
        for (int j = 0; j < nstb; j++) {
            arr[i][j] = rand() % 10;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < nstr; i++) {
        reverse(arr[i], nstb);
    }
    for (int i = 0; i < nstr; i++) {
        for (int j = i + 1; j < nstb; j++) {
            int tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }
    for (int i = 0; i < nstr; i++) {
        reverse(arr[i], nstb);
    }
    printf("\n");
    for (int i = 0; i < nstr; i++) {
        for (int j = 0; j < nstb; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}