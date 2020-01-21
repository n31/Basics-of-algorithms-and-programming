#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

char *setString() {
    rewind(stdin);
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

int wordsCount(char *str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ') i++;
        count++;
        while (str[i] != ' ' && str[i] != '\0') i++;
    }
    return count;
}

int end(char *str, int n) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ') i++;
        count++;
        while (str[i] != ' ') i++;
        if (count == n) break;
    }
    return i - 1;
}

int begin(char *str, int n) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ') i++;
        count++;
        if (count == n) break;
        while (str[i] != ' ') i++; 
    }
    return i;

}

int strins(char *str, int next, int j) {
    str[j] = str[next];
    if (str[next] == '\0') return 0;
    return  strins(str, next + 1, j + 1);
}

int strclr(char *str, int i) {
    if (i == wordsCount(str)) return 0;
    strins(str, begin(str, i + 1), end(str, i) + 2);
    return strclr(str, i + 1);
}

int main() {
    char *str = setString();

    strclr(str, 1);
    
    /*
    for (int i = 1; i < wordsCount(str); i++) {
        int next = begin(str, i + 1);
        int j = end(str, i) + 2;
        while (1) {
            str[j] = str[next];
            if (str[next] == '\0') break;
            j++, next++;
        }
    }*/

    printf("%s", str);
    return 0;
}