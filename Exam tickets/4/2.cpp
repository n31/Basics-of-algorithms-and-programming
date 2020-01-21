#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

int main() {
    char *str = (char*)malloc(1);
    int i = 1, c;
    while((c = getchar()) != EOF && c != '\n') {
        i++;
        str = (char*)realloc(str, i);
        str[i - 2] = c;
        str[i - 1] = '\0';
    }
    int flag = 0;
    i = 0;
    while (str[i] != ' ') {
        i++;
        if (str[i] == '\0') {
            flag = 1;
            break;
        }
    }
    i--;
    for (int j = 0; j < i; j++, i--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    if (!flag) {
        i = 0;
        while (str[i] != '\0') i++;
        int j = i - 1;
        while (str[i] != ' ') i--;
        i++;
        for (; i < j; i++, j--) {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }
    }
    printf("%s\n", str);
    _getch();
    return 0;
}