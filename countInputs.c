// countInputs.c
// To count the number of input values user entered.
#include <stdio.h>

int main(void) {    

	printf("Enter integer values, terminate with ctrl-d\n");

	int count = 0, temp = 0;
	while (scanf("%d", &temp) == 1) {
		count++;
	}

	printf("Number of values entered = %d\n", count);

	return 0;
}

