#include "recursion.h"

void print_records(Student* arr, int size)
{
	for (int index = 0; index < size; ++index)
	{
		printf("arr[%d]: %s, %s, %u, %.2lf\n", index, arr[index].last,
			arr[index].first, arr[index].id, arr[index].gpa);
	}
}

Student *bubble_sort(Student *arr_students, int size) {
    // temp student variable
    Student tmp;
    
    // or instead, check for whether or not passes happened as the terminating condition
    
    // this outer loop controls number of times a sorting pass runs
    for (int passes=1; passes < size; passes++) {
        // this inner loop does the sorting
        for (int index=0; index < size - passes; ++index) {
            if (arr_students[index].gpa > arr_students[index+1].gpa) {
                // swap
                tmp = arr_students[index];
                arr_students[index] = arr_students[index+1];
                arr_students[index+1] = tmp;
            }
        }
    }

    return arr_students;
}