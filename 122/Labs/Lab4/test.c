/*
 * File: test.c
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 4
 */

#include "test.h"

void test_all() {

	printf("TEST IS EMPTY: ");
	if (test_isEmpty()) printf("PASSED\n");
	else printf("FAILED\n");

	printf("TEST PUSH: ");
	if (test_push()) printf("PASSED\n");
	else printf("FAILED\n");

	printf("TEST POP: ");
	if (test_pop()) printf("PASSED\n");
	else printf("FAILED\n");

	printf("TEST PEEK: ");
	if (test_peek()) printf("PASSED\n");
	else printf("FAILED\n");
}

int test_isEmpty() {

	// check for is empty true
	Node* pStack = NULL;
	int empty = isEmpty(pStack);

	// check for is empty false
	push(&pStack, 1);
	int full = isEmpty(pStack);

	pop(&pStack); // remove the top node to not have a memory leak

	if (empty && !full) // success
		return 1;
	else // failed
		return 0;
}

int test_push() {

	Node* pStack = NULL;

	int success1 = push(&pStack, 1);
	int success2 = push(&pStack, 2);

	int success3 = 0;
	int success4 = 0;

	if (pop(&pStack) == 2)
		success3 = 1;
	if (pop(&pStack) == 1)
		success4 = 1;

	int success5 = isEmpty(pStack);

	if (success1 && success2 && success3 && success4 && success5) return 1; // success
	else return 0; // failiure
}

int test_pop() {

	// due to the nature of pushing and popping, one test is sufficient to determine
	// the validitiy of both (in my opinion)
	return test_push();
}

int test_peek() {

	Node* pStack = NULL;

	int success1 = push(&pStack, 1);
	int success2 = push(&pStack, 2);

	int success3 = 0;
	int success4 = 0;

	if (peek(pStack) == 2)
		success3 = 1;
	if (peek(pStack) == 2)
		success4 = 1;

	int success5 = isEmpty(pStack); // should not be empty - we only peeked

	// delete stack to avoid memory leak
	pop(&pStack);
	pop(&pStack);

	if (success1 && success2 && success3 && success4 && !success5) return 1; // success
	else return 0; // failiure
}