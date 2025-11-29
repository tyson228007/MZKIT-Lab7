#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#define MAX_RANGE 20
#define MIN_RANGE -20
#define MATRIX_SIZE 10
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(NULL));
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	int max = -1e5, min = 1e5;
	int index_max = 0;
	int index_min = 0;
	printf("Згенерована матриця Е:\n");

	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			const int r = (rand() % MAX_RANGE * 3) + MIN_RANGE;
			matrix[i][j] = r;
			printf("%4d ", r);
			if (r > max) {
				max = r;
				index_max = i;
			}
			if (r < min) {
				min = r;
				index_min = i;
			}
		}
		printf("\n");
	}
	if (index_max != index_min) {
		for (int k = 0; k < MATRIX_SIZE; k++) {
			const int temp = matrix[index_max][k];
			matrix[index_max][k] = matrix[index_min][k];
			matrix[index_min][k] = temp;
		}
	}

	printf("Змінена матриця:\n");
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			printf("%4d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
Я изменила этот файл