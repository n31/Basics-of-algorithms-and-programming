#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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
}

bool thisLetterGood(char c) {
    int ascii = c;
    if (ascii >= 'a' && ascii <= 'o') return true;
    return false;
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

int begin(char *str, int n) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ') i++;
        count++;
        if (count == n) break;
        while (str[i] != ' ' && str[i] != '\0') i++;
    }
    return i;
}

int end(char *str, int n) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ') i++;
        count++;
        while (str[i] != ' ' && str[i] != '\0') i++;
        if (count == n) break;
    }
    return i - 1;
}

bool wordConsistOnlyGoodLetters(char *str, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (!thisLetterGood(str[i])) return false;
    }
    return true;
}

int findd(char *str) {
   for (int i = 1; i <= wordsCount(str); i++) {
       if (wordConsistOnlyGoodLetters(str, begin(str, i), end(str, i))) {
           for (int j = begin(str, i); j <= end(str, i); j++) {
               printf("%c", str[j]);
           }
           printf("\n");
           break;
       }
   } 
}

int main() {
    int size;
    scanf("%d", &size);
    char **str = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) str[i] = setString();

    for (int i = 0; i < size; i++) findd(str[i]);

    return 0;
}