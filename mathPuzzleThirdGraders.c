#include <stdio.h>
#include <stdlib.h>

void initializeArray(float *array, int arrayLength) {
	int i;

	for(i = 0; i < arrayLength; i++) {
		array[i] = (float)i+1.0;
	}
}

void printArray(float *array, int arrayLength) {
	int i;

	for(i = 0; i < arrayLength; i++) {
		printf("%g", array[i]);
	}
	printf("\n");
}

void swap(float *array, int x, int y) {
	float tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}


void solvePuzzle(float * array, int arrayLength) {
	float result;

	result = array[0] + ((13 * array[1]) / array[2]) + array[3] + (12 * array[4]) - array[5] - 11 + ((array[6] * array[7]) / array[8]) -10;

	if(result == 66) {
		printf("Result: %g\n", result);
		printArray(array, arrayLength);
	}
}

void permute(float *array, int left, int right, int arrayLength) {
	int i;
	if(left == right) {
		solvePuzzle(array, arrayLength);
	}
	else {
		for (i = left; i <= right; i++) {
			swap(array, left, i);
			permute(array, left+1, right, arrayLength);
			swap(array, left, i); // Backtrack
		}
	}
}

void main() {

	float array[9];
	int arrayLength = (sizeof(array)/sizeof(int));

	initializeArray(array, arrayLength);
	permute(array, 0, arrayLength-1, arrayLength);
}
