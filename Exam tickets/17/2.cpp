#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float fsum(int i, float f) {
    return i + f;
}

int main() {
    int i; float f;
    scanf("%d %f", &i, &f);
    printf("sum is: %f", fsum(i, f));
    return 0;
}