#include "TestStack.h"

void testPushOnEmptyStack(void) {
	// test point? 
	Stack s = { NULL };
	Data testData = { 'A' };
	int success = 0;

	success = push(&s, testData);

	// expected results?
	// success == 1
	// top stack data = 'A'
	// ptop != NULL

	if (s.pTop) {
		printf("Test for pTop: PASS\n");

		if (s.pTop->myData.symbol == testData.symbol) {
			printf("Test for data at top: PASS\n");
		}
		else {
			printf("Test for data at top: FAIL\n");
		}
	}
	else {
		printf("Test for pTop FAIL\n");
	}

	if (success == 1) {
		printf("Test for success=1 PASS\n");
	}
	else {
		printf("Test for success=1 FAIL\n");
	}
}