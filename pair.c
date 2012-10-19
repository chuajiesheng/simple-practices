#include <stdio.h>

int findPair(int *arr, int size, int sum, int *one, int *two) {
	int i;
	for (i = 0; i < (size - 1); i++) {
		int j;
		for (j = i+1; j < size; j++) {
			if (arr[i] + arr[j] == sum) {
				printf("sum %d %d\n", arr[i], arr[j]);
				*one = arr[i];
				*two = arr[j];
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int size;

	printf("Please enter the number of elements: ");
	scanf("%d", &size);

	int arr[size];
	int i = 0;
	for (i = 0; i < size; i++) {
		arr[i] = 0;
	}
	//input the elements into array
	printf("Please enter %d integers: ", size);

	i = 0;
	char c = getchar();
	do {
		c = getchar();
		//printf("%d ", c);
		if (c > 47 && c < 58) {
			arr[i] = (arr[i] * 10) + (c - '0');
		} else if (c == ' ' || c == '\n') {
			i++;
		}
	} while (i < size);


	for (i = 0; i < size; i++) {
		//printf("%d ", arr[i]);
	}
	

	printf("Please enter the target sum: ");
	int sum = 0;
	scanf("%d", &sum);
	//printf("sum: %d\n", sum);
	
	int one, two;
	int found = findPair(arr, size, sum, &one, &two);
	if (found) {
		printf("found\n");
	} else {
		printf("not found\n");
	}

	return 0;
}
