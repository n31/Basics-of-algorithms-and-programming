#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

int fibonacci(int n) {
    return (n == 0 || n == 1) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}