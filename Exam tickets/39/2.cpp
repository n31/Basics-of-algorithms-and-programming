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
    return str;
}

int strsize(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
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

int wordsCount(char *str) {
    int count = 0;
    int i = 0;
    while(str[i] != '\0') {
        while (str[i] == ' ') i++;
        count++;
        while (str[i] != ' ' && str[i] != '\0') i++;
    }
    return count;
}

int recc(char *str, int i, int j) {
    if (j > strsize(str)) return 1;
    str[i] = str[j];
    return recc(str, i + 1, j + 1);
}

int main() {
    char *str = setString();

    if (wordsCount(str) > 2) {
        printf("o_O words count > 2 so I am working now...\n");
        /*for (int i = begin(str, 2), j = begin(str, 3); j <= strsize(str); j++, i++) {
            printf("i = %d, j = %d\n", i, j);
            str[i] = str[j];
            printf("%s\n", str);
        }*/
        recc(str, begin(str, 2), begin(str, 3));
        printf("Done! :)\n");
    }
    else if (wordsCount(str) == 2) {
        str[begin(str, 2) - 1] = '\0';
    }

    printf("%s", str);
    return 0;
}