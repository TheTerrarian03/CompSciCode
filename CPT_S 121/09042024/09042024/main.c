#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define G 6.67e-11

int main() {
	char symbol = '\o'; // ascii code 0, null
	
	printf("%.13lf\n\n", G);

	printf("aaaaaaa");
	scanf("%d");


	printf("Enter a character: ");
	scanf(" %c", &symbol);
	printf("Result: %c\n", symbol + 5);
}