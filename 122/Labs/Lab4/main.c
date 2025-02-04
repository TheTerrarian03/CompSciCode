/*
 * File: main.c
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 4
 */

#include "lab4.h"
#include "test.h"

int main() {
	seedRand();

	// test stack functions
	test_all();

	printf("\n---- MAZE ----\n\n");

	int maze[MAZE_HEIGHT][MAZE_WIDTH];

	initMaze(maze);
	genMaze(maze);
	printMaze(maze);

	// Point start = 

	return 0;
}