#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

void insertsort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        int tmp = arr[i];
        while (j >= 0 && tmp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

int main() {
    srand(time(0));
    int nstr, nstb;
    scanf("%d %d", &nstr, &nstb);
    int **arr = (int**)malloc(nstr * sizeof(int*));
    for (int i = 0; i < nstr; i++) {
        arr[i] = (int*)malloc(nstb * sizeof(int));
        for (int j = 0; j < nstb; j++)  {
            arr[i][j] = rand() % 10;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int n;
    scanf("%d", &n);
    insertsort(arr[n], nstb);
    for (int i = 0; i < nstr; i++) {
        for (int j = 0; j < nstb; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}