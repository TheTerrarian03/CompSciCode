/*
 * File: lab4.h
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 4
 */

// guard code
#ifndef LAB4_H
#define LAB4_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // REQUIRED for malloc
#include <string.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 5

// a stack is a restricted list, so the underlying data type isn't any different
typedef struct point {
	int x;
	int y;
} Point;

typedef struct node {
	Point pos;
	double data;
	struct node* pNext;
} Node;

#pragma region Random Funcs

void seedRand();
int getRandBool();
int getRandRangeInc(int max_inc);
int getRandRangeExcl(int max_excl);

#pragma endregion

#pragma region Stack Operations

/*
	Determines if a stack is empty or not

	@param a pointer to the top of the stack
	@return 1 if empty, 0 otherwise
*/
int isEmpty(Node* pTop);

/*
	Inserts a new node onto the top of the stack

	@param a double pointer to the top of the stack
	@param the data to insert

	@return success value
*/
int push(Node** pTop, double data);

/*
	Removes the top of the stack

	@param a double pointer to the top of the stack

	@param the data removed - if any
*/
double pop(Node** pTop);

/*
	Determines the value at the top of the stack

	@param a pointer to the top of the stack

	@return the data at the top of the stack - if any
*/
double peek(Node* pTop);

#pragma endregion

#pragma region Maze Operations

void initMaze(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]);

void genMaze(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]);

Point randValidStart(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]);
Point randValidEnd(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]);

void printMaze(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]);

#pragma endregion

#endif
