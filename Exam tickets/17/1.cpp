#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void recc(int n, int c) {
    if (n < 1) return;
    else {
        int k;
        scanf("%d", &k);
        recc(n - 1, c + 1);
        printf("%d) %d\n", c, k);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    recc(n, 1);
    return 0;
}