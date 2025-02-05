#include "Stack.h"
#include "TestStack.h"
#include "reverseString.h"

int main(void) {
	char str[10] = "cat";

	puts(reverseString(str));

	return 0;
}