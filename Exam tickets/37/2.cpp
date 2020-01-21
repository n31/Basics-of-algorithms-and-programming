#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// 0 - [
// 1 - ]

int strsize(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int countOf(char *str, char c) {
    int count = 0;
    for (int i = 0; i < strsize(str); i++) {
        if (str[i] == c) count++;
    }
    return count;
}

bool recc(char *str, int openCount, int closeCount, int queue, int i, bool good) {
    if (i == strsize(str)) return good;
    if (!queue) {
        if (str[i] == '[') return recc(str, openCount + 1, closeCount, queue, i + 1, good);
        else {
            return recc(str, openCount, closeCount, 1, i, good);
        }
    }
    else {
        if (str[i] == ']') return recc(str, openCount, closeCount + 1, queue, i + 1, good);
        else {
            if (closeCount != openCount) return false;
            return recc(str, 0, 0, 0, i, good);
        }
    }

    return recc(str, openCount, closeCount, queue, i + 1, good);
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

    bool good = recc(str, 0, 0, 0, 0, true);
    int totalCountOpen = countOf(str, '[');
    int totalCountClose = countOf(str, ']');
    if (strsize(str) % 2 != 0) good = false;
    if (totalCountOpen != totalCountClose) good = false;

    

    /*
    int openCount = 0, closeCount = 0;
    int queue = 0;
    for (int i = 0; i < strsize(str); i++) {
        if (!queue) { // очередь открывающихся скобок
            if (str[i] == '[') {
                openCount++;
            }
            else {
                queue = 1;
                i--;
                continue;
            }
        }
        else { // очередь закрывающихся скобок
            if (str[i] == ']') {
                closeCount++;
            }
            else {
                i--;
                queue = 0;
                if (closeCount != openCount) {
                    good = false;
                    break;
                }
                closeCount = 0;
                openCount = 0;
            }
        }*/

        if (good) printf("good!");
        else printf("nope :(");

        return 0;
}