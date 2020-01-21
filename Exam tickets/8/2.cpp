#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

void swapWords(char *str, int begin1, int end1, int begin2, int end2);
int wordsCount(char *str);
int begin(char *str, int n);
int end(char *str, int begin);
void alphabetSort(char *str);

int main() {
    char *str = (char*)malloc(1);
    int i = 1, c;
    while ((c = getchar()) != EOF && c != '\n') {
        i++;
        str = (char*)realloc(str, i);
        str[i - 2] = c;
        str[i - 1] = '\0';
    }

    alphabetSort(str);

    printf("%s", str);
    return 0;
}


void alphabetSort(char *str) {
    int count = wordsCount(str);
    for (int i = 1; i <= count; i++) {
        int imin = i;
        for (int j = i + 1; j <= count; j++) {
            if (str[begin(str, imin)] > str[begin(str, j)]) imin = j;
        }
        swapWords(str, begin(str, i), end(str, begin(str, i)), begin(str, imin), end(str, begin(str, imin)));
    }
}

int end(char *str, int begin) {
    int i = begin;
    while (str[i] != ' ' && str[i] != '\0') i++;
    return i - 1;
}

int begin(char *str, int n) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        while(str[i] == ' ') i++;
        if (str[i] != ' ') count++;
        if (count == n) break;
        while(str[i] != ' ' && str[i] != '\0') i++;
    }
    return i;
}

int wordsCount(char *str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        while(str[i] == ' ') i++;
        if (str[i] != ' ') count++;
        while(str[i] != ' ' && str[i] != '\0') i++;
    }
    return count;
}

void swapWords(char *str, int begin1, int end1, int begin2, int end2) {
    int size1 = end1 - begin1, size2 = end2 - begin2;

    if (size1 >= size2) {
        while (end2 - begin2 >= 0) {
            char tmp = str[begin1];
            str[begin1] = str[begin2];
            str[begin2] = tmp;
            begin1++, begin2++;
        }
        if (size1 != size2) {
            while (end1 - begin1 >= 0) {
                int j = end1--;
                int tmp = str[j];
                while (j <= end2) str[j++] = str[j + 1];
                str[end2--] = tmp;
            }
        }
    }
    else {
        while (end1 - begin1 >= 0) {
            char tmp = str[begin1];
            str[begin1] = str[begin2];
            str[begin2] = tmp;
            begin1++, begin2++;
        }
        if (size1 != size2) {
            while (end2 - begin2 >= 0) {
                int j = begin2++;
                int tmp = str[j];
                while (j >= begin1) str[j--] = str[j - 1];
                str[begin1++] = tmp;
            }
        }
    }
}