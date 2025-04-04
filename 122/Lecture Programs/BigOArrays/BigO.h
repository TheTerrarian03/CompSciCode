#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

using std::vector;

// Namespaces provide a way to organize code and prevent name conflicts in large projects.
// They create a notion of named scope.

namespace BigO
{
	template <class T>
	class SortsAndSearches
	{
	public:
		bool sequential_search(const T *pList, const int size, const T &target, int *pPos);

		// precondition: list must be in order - ascending order
		bool binary_search(const T *pList, const int size, const T &target, int *pPos);

		// ascending order
		void selection_sort(T *pList, const int size);
		void bubble_sort(T *pList, const int size);
	};
}

template <class T>
bool BigO::SortsAndSearches<T>::sequential_search(const T *pList, const int size, const T &target, int *pPos) {
	
	bool found = false;  // 1 op total

	// setters:   2 op initial
	// condition: 3 ops x size+1 iterations
	// update:    1 op x size iterations
	for (int index = 0 /* 1 op */, *pPos = -1 /* 1 op */; !found && index < size /* 3 op */; index++ /* 1 op */) {
		
		// condition: size ops total
		if (pList[index] == target) {  // 1 op
			found = true;  // 1 op
			*pPos = index;  // 1 op
		}
	}

	return found;  // 1 op total

	// [WORST] TOTAL OPS: 5 * size + 7
	// [BEST] TOTAL OPS:  14
}

// precondition: list must be in ascending order
template <class T>
bool BigO::SortsAndSearches<T>::binary_search(const T *pList, const int size, const T &target, int *pPos)
{
	int left_index = 0, right_index = size - 1,
		mid_index = 0, num_comparisons = 0;
	bool found = false;

	*pPos = -1; // this will represent the position/index at which we find the target

	while ((left_index <= right_index) && (!found))
	{
		mid_index = (left_index + right_index) / 2; // compute the new midpoint

		if (target == pList[mid_index]) // did we find the target?
		{
			// found the target
			found = true;
			*pPos = mid_index;
		}
		else if (target > pList[mid_index])
		{
			left_index = mid_index + 1;
		}
		else
		{
			right_index = mid_index - 1;
		}
	}

	return found;

	// [WORST] TOTAL OPS: log_2(n)
	// [BEST] TOTAL OPS: O(1)
}
//
//// ascending order
//template <class T>
//void BigO::SortsAndSearches<T>::selection_sort(T *pList, const int size)
//{
//	int index = 0, passes = 1, pos = 0;
//	T max, temp;
//
//	for (passes = 1; passes < size; ++passes) // used to determine how many passes
//	{
//		max = pList[0];
//		pos = 0;
//
//		// sorting happens - swaps
//		for (index = 0; index < size - passes + 1; ++index)
//		{
//			if (max < pList[index]) // found new max?
//			{
//				max = pList[index];
//				pos = index;
//			}
//		}
//
//		// swap
//		temp = max;
//		pList[pos] = pList[size - passes];
//		pList[size - passes] = temp;
//	}
//}
//
// ascending order
template<class T>
void BigO::SortsAndSearches<T>::bubble_sort(T *pList, const int size)
{
	int index = 0, passes = 1;
	T temp;

	for (; passes < size; ++passes)
	{
		// the sorting happens
		for (index = 0; index < size - passes; ++index)
		{
			if (pList[index] > pList[index + 1]) // swap?
			{
				temp = pList[index];
				pList[index] = pList[index + 1];
				pList[index + 1] = temp;
			}
		}
	}
}

// reverse string complexity (meet in middle)
	// find end:
		// time complexity O(n)
		// space complexity O(1)
	// reverse string
		// time complexity O(n)
		// space complexity O(1)
	// total: O(n+n) or still O(n)
// reverse string complexity (brute force add another array)
	// find end still same
	// reverse:
		// time complexity O(n)
		// space complexity O(n)
	