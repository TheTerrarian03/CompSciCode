/*
 * File: main.cpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 11
 * Created: March 29, 2025
 */

#include "Interpreter.hpp"
#include "Sorting.hpp"

int main() {

	// uncomment to test your merge sort function!
	Sorting::testSortFromCSV("large_arrays.csv", 1000000);

	// int x[] = {2, 1, 3, 5, 6};
	// Sorting::testSort(x, 5);
    
	// uncomment to play around with your BST!
	//Interpreter::run();

	return 0;
}

// merge:
// find middle, favor one side
// merge sort left
// merge sort right
// merge left & right

// merge in array

// save average, worst, and best case: nlog(n)

// delete:
// return boolean for has deleted something?
// base case: no data. do nothing
// data found:
	// is leaf: simply delete, set prev to nullptr
	// one child: delete current, set prev to the one child of the deleted node
	// two children: (else)
		// find successor: go right, the left until no more left
			// swap to-delete and successor
			// delete now-leaf on successor node