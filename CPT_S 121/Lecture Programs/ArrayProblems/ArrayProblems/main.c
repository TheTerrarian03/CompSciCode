/*
yeah
*/

#include <stdio.h>

int print_array(int list[]);

// precondition: size < MAX_SIZE
int sequential_search(int list[], int size, int target);
int binary_search(int list[], int size, int target);

int main() {
	int list[5] = { 0001, 1111, 2222, 3333, 4444};
	int toFind = 3333;
	//int isFound = sequential_search(list, 5, toFind);

	//printf("Is found? %d", isFound);

	int isFound = binary_search(list, 5, toFind);
	printf("Is found? %d", isFound);
	
	return 0;
}

print_array(int list[], int size) {
	printf("{");

	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d", list[i]);
		} 
		else {
			printf(", %d", list[i]);
		}
	}
	printf("}");
}

//int sequential_search(int list[], int size, int target) {
//	int index = 0, found = 0;
//
//	for (index = 0, found = 0; !found && index < size; ++index) {
//		if (list[index] == target) {
//			found = 1;
//		}
//	}
//
//	return found;
//}

int binary_search(int list[], int size, int target) {
	int found = 0, left = 0, right = size-1, mid = right / 2;

	while 

	return found;
}