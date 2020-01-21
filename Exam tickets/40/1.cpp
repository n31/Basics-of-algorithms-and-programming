#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

void quicksort(int *arr, int l, int r) {
    int mid = arr[(r + l) / 2];
    int i = l, j = r;
    do {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; j--;
        }
    } while (i <= j);

    if (i < r) quicksort(arr, i, r);
    if (j > l) quicksort(arr, l, j);
}

int main() {
    int size;
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    quicksort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    return 0;
}