#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// A -  -128
// Я -  -97
bool isUpperCaseRussianLetter(char c) {
    int ascii = c;
    if (ascii >= -128 && ascii <= -97) return true;
    return false;
}

int countWords(char *str) {
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
        while (str[i] != ' ') i++;
    }
    return i;
}

int howManyWordsWithUpperRussianLettersInString(char *str) {
    int count = 0;
    for (int i = 1; i <= countWords(str); i++) {
        if (isUpperCaseRussianLetter(str[begin(str, i)])) count++;
    }
    return count;
}

int stringWithMaxUpperCaseRussianLetters(char **str, int i, int size, int imax) {
    if (i == size) return imax;
    if (howManyWordsWithUpperRussianLettersInString(str[i]) > howManyWordsWithUpperRussianLettersInString(str[imax])) {
        return stringWithMaxUpperCaseRussianLetters(str, i + 1, size, i);
    }
    return stringWithMaxUpperCaseRussianLetters(str, i + 1, size, imax);
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

    
    int imax = stringWithMaxUpperCaseRussianLetters(str, 0, size, 0);

    printf("%s", str[imax]);

    return 0;
}