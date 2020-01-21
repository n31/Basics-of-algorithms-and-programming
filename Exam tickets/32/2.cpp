#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

int strsize(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int poww(int n, int s) {
    int ans = 1;
    for (int i = 0; i < s; i++) {
        ans *= n;
    }
    return ans;
}

int strtoint(char *str) {
    int num = 0;
    for (int i = 0, dig = poww(10, strsize(str) - 1); i < strsize(str); i++, dig /= 10) {\
        int d = str[i] - '0';
        num += dig * d;
    }
    return num;
}

bool visocoso(int n) {
    if (n % 4 == 0 && n % 100 != 0 && n % 400 != 0) return true;
    return false;
}

int main(int args, char *argv[]) {
    int sum = 0;
    for (int i = 0; i < args; i++) {
        if (visocoso(strtoint(argv[i]))) sum += strtoint(argv[i]);
    }

    printf("%d", sum);

    return 0;
}