#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int multiply(int a, int b);

int main() {
	int arraySize;
	int* pArray1;
	int* pArray2;

	printf("Enter array size: ");
	scanf("%d", &arraySize);
	printf("Creating 2 arrays of size %d...\n", arraySize);

	pArray1 = (int*)malloc(arraySize * sizeof(int));
	pArray2 = (int*)malloc(arraySize * sizeof(int));

	if (pArray1 == NULL) {
		printf("Array 1 memory allocation failed");
		return 1;
	}
	else if (pArray2 == NULL) {
		printf("Array 2 memory allocation failed");
		return 1;
	}
	printf("Memory allocation successful for both arrays\n");
	printf("Address of first array: %p\n", pArray1);
	int array1Size = sizeof(pArray1);
	printf("Size of array 1 pointer: %d\n", array1Size);

	for (int i = 0; i < arraySize; i++) {
		printf("Enter int value of array 1 at index %d: ", i);
		scanf("%d", &pArray1[i]);
	}

	for (int i = 0; i < arraySize; i++) {
		printf("Enter int value of array 2 at index %d: ", i);
		scanf("%d", &pArray2[i]);
	}

	for (int i = 0; i < arraySize; i++) {
		printf("Array 1 at index %d: %d\n", i, pArray1[i]);
	}

	for (int i = 0; i < arraySize; i++) {
		printf("Array 2 at index %d: %d\n", i, pArray2[i]);
	}
	int num1;
	int num2;

	printf("Enter multiplication int 1: ");
	scanf("%d", &num1);

	printf("Enter multiplication int 2: ");
	scanf("%d", &num2);

	printf("Multiplying %d and %d...\n", num1, num2);
	printf("Result is %d\n", multiply(num1, num2));

	FILE *fptr;

	printf("Opening file...\n");
	fptr = fopen("hw1_output.txt", "w");

	for (int i = 0; i < arraySize; i++) {
		int result;

		result = multiply(pArray1[i], pArray2[i]);

		printf("Array1[%d] * Array2[%d] = %d\n", i, i, result);

		if (result % 2 == 0) {
			printf("%d is an even number\n", result);
		}
		else {
			printf("%d is an odd number\n", result);
		}

		fprintf(fptr, "%d\n", result);
	}
	printf("Closing file...\n");
	fclose(fptr);
	printf("Opening file...\n");
	fptr = fopen("hw1_output.txt", "r");

	char s;

	printf("Reading file...\n");
	while ((s = fgetc(fptr)) != EOF) {
		printf("%c", s);
	}
	printf("Closing file...\n");
	fclose(fptr);

	return 0;
}

int multiply(int a, int b) {
	return a * b;
}