#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

int strsize(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

void strreve(char *str) {
     int i = 0, j = strsize(str) - 1;
     for (; i < j; i++, j--) {
         char tmp = str[i];
         str[i] = str[j];
         str[j] = tmp;
     }
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
    for (int i = 0; i < size; i++) {
        strreve(str[i]);
        printf("%s\n", str[i]);
    }
    return 0;
}