#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

void shellsort(int *arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        int flag;
        do {
            flag = 0;
            for (int i = 0, j = gap; j < size; j++, i++) {
                
                if (arr[i] < arr[j]) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    flag = 1;
                }
            }
        } while (flag);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    shellsort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}