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
	// test_all();

	printf("\n---- MAZE ----\n\n");

	int maze[MAZE_HEIGHT][MAZE_WIDTH];

	initMaze(maze);
	genMaze(maze);

	Point start = randValidStart(maze);
	Point end = randValidEnd(maze);

	printf("Start: %d, %d\n", start.coord.x, start.coord.y);
	printf("End: %d, %d\n", end.coord.x, end.coord.y);

	Node *pTop = NULL;
	push(&pTop, end);

	// printMaze(maze, start, end, pTop);

	mazeSolveLoop(maze, start, end, &pTop);

	return 0;
}