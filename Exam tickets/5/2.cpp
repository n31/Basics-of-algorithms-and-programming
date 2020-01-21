#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

char *setString() {
    char *str = (char*)malloc(1);
    int i = 1, c;
    while ((c = getchar()) != EOF && c != '\n') {
        i++;
        str = (char*)realloc(str, i);
        str[i - 2] = c;
        str[i - 1] = '\0';
    }
    return str;
}

int strsize(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

void strSwap(char *str1, char *str2) {
    char *tmp = (char*)malloc(strsize(str1));
    for (int i = 0; i <= strsize(str1); i++) {
        tmp[i] = str1[i];
    }
    str1 = (char*)realloc(str1, strsize(str2));
    for (int i = 0; i <= strsize(str2); i++) {
        str1[i] = str2[i];
    }
    str2 = (char*)realloc(str2, strsize(tmp));
    for (int i = 0; i <= strsize(tmp); i++) {
        str2[i] = tmp[i];
    }
}

void rec(char *str1, char *str2, int n) {
    str1 = (char*)realloc(str1, strsize(str1) + strsize(str2));
    int j = 0;
    for (int i = n;; i++, j++) {
        str1[i] = str2[j];
        if (str2[j] ==  '\0') break;
    }
    str1 = (char*)realloc(str1, strsize(str1));
    printf("%s, size = %d", str1, strsize(str1));
}

int main() {
    char *str1 = setString();
    rewind(stdin);
    char *str2 = setString();
    rewind(stdin);
    int n;
    scanf("%d", &n);

    if (strsize(str1) < strsize(str2)) strSwap(str1, str2);
    rec(str1, str2, n);
    
    return 0;
}