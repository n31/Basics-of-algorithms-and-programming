#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {

}

void swapWords(char *str, int b1, int e1, int b2, int e2) {
    int s1 = e1 - b1, s2 = e2 - b2;
    if (s1 >= s2) {
        while (e2 - b2 >= 0) {
            char tmp = str[b1];
            str[b1] = str[b2];
            str[b2] = tmp;
            b1++, b2++;
        }
        if (s1 != s2) {
            while (e1 - b1 >= 0) {
                int j = e1--;
                int tmp = str[j];
                while (j <= e2) str[j++] = str[j + 1];
                str[e2--] = tmp;
            }
        }
    }
    else {
        while (e1 - b1 >= 0) {
            char tmp = str[b1];
            str[b1] = str[b2];
            str[b2] = tmp;
            b1++, b2++;
        }
        if (s1 != s2) {
            while (e2 - b2 >= 0) {
                int j = b2++;
                char tmp = str[j];
                while (j >= b1) str[j--] = str[j - 1];
                str[b1++] = tmp; 
            }
        }
    }
}