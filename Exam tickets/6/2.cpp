#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

int sizz(char *str, int i) {
    return (str[i] == '\0') ? i : sizz(str, i + 1);
}

int buff(char *str, int i) {
    if (i == 0) return 0;
    return (str[i - 1] == ' ') ? i : buff(str, i - 1);
}

int begg(char *str, int i) {
    if (i == -2) return 0;
    return (str[i - 1] == ' ') ? i : begg(str, i - 1);
}

int recc(char *str, int begg, int buff) {
    if (begg == buff) return 0;
    return ((str[begg] = str[buff]) != 0) ? recc(str, begg + 1, buff + 1) : 0;
}

int main() {
    char *str = (char*)malloc(1);
    int i = 1, c;
    while ((c = getchar()) != EOF && c != '\n') {
        i++;
        str = (char*)realloc(str, i);
        str[i - 2] = c;
        str[i - 1] = '\0';
    }
    recc(str, begg(str, buff(str, sizz(str, 0)) - 2), buff(str, sizz(str, 0)));
    /*int i = 0;
    while (str[i] != '\0') i++;
    while (str[i] != ' ') {
        i--;
        if (i == 0) {
            printf("%s", str);
            return 0;
        }
    }
    int buf = i + 1;
    i--;
    while (str[i] != ' ') {
        i--;
        if (i == 0) break;
    }
    if (i != 0) i++;
    while ((str[i] = str[buf]) != 0) {
        buf++;
        i++;
    }*/
    printf("%s", str);
    return 0;
}