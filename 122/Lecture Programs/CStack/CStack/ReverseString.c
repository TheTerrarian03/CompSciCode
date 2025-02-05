#include "ReverseString.h"

char* reverseString(char* str) {
	Stack s = { NULL };
	Data d = { '\0' };
	int success = 0;
	int index = 0;

	initStack(&s);


	while (str[index] != '\0') {
		d.symbol = str[index];  // copy character
		success = push(&s, d);  // push onto stack
		index++;
	}

	index = 0;
	while (!isEmpty(&s)) {
		d = peek(&s);  // get data struct
		pop(&s);       // remove top Node
		str[index] = d.symbol;
		index++;
	}
}