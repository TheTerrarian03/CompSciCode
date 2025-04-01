/*
 * File: Sorting.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 11
 * Created: March 29, 2025
 */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// static class for sorting stuff - primarily merge sort
class Sorting {

private:

	// performs mergesort on the arr with start and end indices specified
	template<typename T>
	static T* mergesort(T* arr, int start, int end);

	// performs a merge of 2 sorted arrays, from start - mid, and mid + 1 - end
	template<typename T>
	static T* merge(T* arr, int start, int mid, int end);

public:

	Sorting() = delete; // enforce static class

	// performs a merge sort on an T array of n elements
	template <typename T> 
	static T* mergesort(T* arr, int n);

#pragma region Testing

	// determines if an array is sorted or not
	template <typename T> 
	static bool isSorted(T* arr, int n);

	// prints an array to the screen
	template <typename T>
	static void printArray(T* arr, int n);

	// test funciton for array sorting
	template <typename T>
	static bool testSort(T* arr, int n);

	// tests an upperbounded number of lines as arrays from a file
	static bool testSortFromCSV(const std::string& filename, int upperBoundLines);

#pragma endregion
};

// recursive merge sort function, given array plus start and end of region to merge sort on
template <typename T>
T* Sorting::mergesort(T* arr, int start, int end) {
	// std::cout << "Reccursive merge on array with start " << start << " and end " << end << std::endl;

	if (start == end) {
		// std::cout << "single item found!" << std::endl;
		return arr;
	}

	// find middle
	int middle = start + ((end - start) / 2);

	// std::cout << "Middle index: " << middle << std::endl;

	// merge sort left
	mergesort(arr, start, middle);

	// merge sort right
	mergesort(arr, middle + 1, end);

	// then merge arrays
	merge(arr, start, middle, end);

	return nullptr;
}

template<typename T>
T* Sorting::merge(T* arr, int start, int mid, int end) {
	// std::cout << "Merging array with start " << start << ", middle " << mid << ", and end " << end << std::endl;

	// pointer (index) to left and right in the array, plus sorted
	int l = start,
		r = mid+1,
		s = 0;

	// std::cout << l << " " << r << " " << s << std::endl;

	// size of sorted array
	int s_len = end-start+1,
		l_len = mid-start+1,
		r_len = end-start;
	
	// std::cout << "lens: s" << s_len << " l" << l << " r" << r << std::endl;

	// dynamic int array to store sorted values into
	int *sorted = new int [s_len];

	// loop to sort items into the new array
	for (; s < s_len; s++) {
		// left run out, add from right
		if (l > mid) {
			sorted[s] = arr[r];
			r++;
		}
		// right run out, add from left
		else if (r > end) {
			sorted[s] = arr[l];
			l++;
		}
		// left less than right, add from left
		else if (arr[l] < arr[r]) {
			sorted[s] = arr[l];
			l++;
		}
		// right smaller or equal
		else {
			sorted[s] = arr[r];
			r++;
		}
	}
	
	// std::cout << "Sorted: " << std::endl;
	for (int i=0; i < s_len; i++) {
		// std::cout << sorted[i] << " ";
		arr[start+i] = sorted[i];
	}
	// std::cout << std::endl;

	// delete the dynamic arrays
	delete [] sorted;

	return arr;
}

// main function called, given whole array and length of that array
template <typename T>
T* Sorting::mergesort(T* arr, int n) {

	return mergesort(arr, 0, n - 1);
}

#pragma region Testing

template <typename T>
bool Sorting::isSorted(T* arr, int n) {

	for (int i = 0; i < n - 1; i++) {

		
		if (arr[i] > arr[i + 1]) return false;
	}

	return true;
}

template <typename T>
void Sorting::printArray(T* arr, int n) {

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
bool Sorting::testSort(T* arr, int n) {
	Sorting::mergesort(arr, n);
	printArray(arr, n);
	bool success = Sorting::isSorted(arr, n);
	std::cout << "Sorted successfully: "
		<< (success ? "YES" : "NO")
		<< std::endl << std::endl;
	return success;
}

bool Sorting::testSortFromCSV(const std::string& filename, int upperBoundLines = 1000000) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << "\n";
		return false;
	}

	std::string line;
	int lineNumber = 1;

	while (std::getline(file, line) && lineNumber < upperBoundLines) {
		std::stringstream ss(line);
		std::vector<int> values;
		std::string item;

		while (std::getline(ss, item, ',')) {
			std::stringstream converter(item);
			int number;
			if (converter >> number) {
				values.push_back(number);
			}
		}

		std::cout << "Testing array from line " << lineNumber << ":\n";
		if (!values.empty()) {
			auto success = testSort(values.data(), values.size());

			if (!success) {
				std::cout << "Line " << lineNumber << " failed!" << std::endl;
				return false;
			}
		}
		else {
			std::cout << "Error: Line " << lineNumber << " contains no integers or invalid format.\n\n";
		}

		lineNumber++;
	}

	std::cout << "passed all tests" << std::endl;
	file.close();
	return true;
}
#pragma endregion
