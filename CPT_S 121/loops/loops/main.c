#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int count = 1;
	int sum_scores = 0;
	int score = 0;

	FILE* infile = fopen("scores.txt", "r");

	while (!feof(infile)) {
		fscanf(infile, "%d", &score);
		sum_scores += score;
	}

	printf("SCORE: %d\n", sum_scores);

	while (count <= 10) {
		printf("while loop iteration #%d\n", count);
		count++;
	}

	for (count = 1; count <= 10; count++) {
		printf("for loop iteration #%d\n", count);
	}

	count = 1;
	do {
		printf("do while iteration #%d\n", count);
		count++;
	} while (count <= 10);

	return 0;
}