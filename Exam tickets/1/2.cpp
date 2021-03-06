#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

int strsize(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int main() {
    int size;
    scanf("%d", &size);
    char **str = (char**)malloc(size * sizeof(char*));
    for (int j = 0; j < size; j++) {
        rewind(stdin);
        str[j] = (char*)malloc(1);
        int i = 1, c;
        while ((c = getchar()) != EOF && c != '\n') {
            i++;
            str[j] = (char*)realloc(str[j], i);
            str[j][i - 2] = c;
            str[j][i - 1] = '\0';
        }
    }
    int max = 0;
    for (int i = 1; i < size; i++) {
        if (strsize(str[max]) < strsize(str[i])) max = i;
    }
    printf("%s", str[max]);
    return 0;
}