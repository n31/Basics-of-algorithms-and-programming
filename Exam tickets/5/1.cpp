#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

// min в строке и max в столбце
//  7 18 5 10 15
//  8 28 0 14 16
//  7 11 1 17 34
//  2 45 4 55 11
//  4 21 2 22 45
//
//  i = 0, j = 2

int main() {
    srand(time(0));
    int nstr, nstb;
    scanf("%d %d", &nstr, &nstb);
    printf("nstr = %d\nnstb = %d\n", nstr, nstb);
    int **arr = (int**)malloc(nstr * sizeof(int*));
    for (int i = 0; i < nstr; i++) {
        arr[i] = (int*)malloc(nstb * sizeof(int));
    }

    for (int i = 0; i < nstr; i++) {
        for (int j = 0; j < nstb; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    int find = 0;

    for (int i = 0; i < nstr; i++) {
        for (int j = 0; j < nstb; j++) {
            int min = 1;
            int jmin = j;
            for (int k = 0; k < nstb; k++) {
                if (k == j) continue;
                if (arr[i][jmin] > arr[i][k]) min = 0;
            }
            if (min) {
                int max = 1;
                int dmax = i;
                for (int d = 0; d < nstr; d++) {
                    if (d == i) continue;
                    if (arr[dmax][jmin] < arr[d][jmin]) max = 0;
                }
                if (max) {
                    printf("i = %d, j = %d\n", i, j);
                    find = 1;
                }
            }
        }
    }

    if (!find) printf("not found");
    return 0;
}