#include <stdio.h>

int isOdd(int no) {
	return no % 2 == 1;
}

int totalOddDigits(int no) {
	int p = 1;
	int total = 0;

	while ((no / p) != 0) {
		int check = (no % (p*10) / p);
		//printf("%d\n", check);
		p *= 10;

		if (isOdd(check)) {
			total += check;
			printf("+ %d ", check);
		}
	}
	return total;
}

int main() {
	int input = 99;
	int check = 1;
	int total = 0;

	printf("input: %d\n", input);
	do {
		if (total != 0) {
			printf("%d ", total);
			check = totalOddDigits(total);
		} else {
			printf("%d ", total);
			check = totalOddDigits(input);
		}
		
		if (check != 0) {
			total += check;
			printf("= %d\n", total);
		}
	} while (check != 0);
}
