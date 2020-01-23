#include <stdio.h>
#include <conio.h>

int sqrt(int number) {
	register unsigned int temp, x;
	if (number < 0)
		number = -number;
	for (temp = 0, x = 1u << (sizeof(unsigned int) * 4 - 1); x; x >>= 1) {
		if ((temp | x) * (temp | x) <= number)
			temp |= x;
	}
	return temp;
}

int ravn_trap(int srlin, int bokstr) {
	return srlin * 2 + bokstr * 2;
}

int priam(int str1, int str2) {
	return 2 * (str1 + str2);
}

int romb(int dig1, int dig2) {
	return 4 * sqrt((dig1 * dig1 + dig2 * dig2) / 4);
}

int priam_tr(int kat1, int kat2) {
	return kat1 + kat2 + sqrt(kat1 * kat2 + kat2 * kat2);
}

int(*menu[])(int a, int b) = {
	ravn_trap, priam, romb, priam_tr
};

int main() {
	int choice, param1, param2, res;
	printf_s("Menu:\n1) Ravnobedrennaya trapecia\n2) Priamoygolnik\n3) Romb\n4) Priamoygol`naya trapecia\nYour choice [1-4]: ");
	scanf_s("%d", &choice);
	if (choice < 1 || choice > 4) return 0;
	printf_s("Param1: ");
	scanf_s("%d", &param1);
	printf_s("Param2: ");
	scanf_s("%d", &param2);
	res = menu[choice - 1](param1, param2);
	printf("Result: %d", res);
	_getch();
	return 0;
}