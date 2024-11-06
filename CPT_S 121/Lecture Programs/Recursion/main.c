#include "recursion.h"

int main() {
	Student arr_students[100] = { {.last = "", .first = "", .id = -1, .gpa = 0.0}};
	char line[150] = "";
	int line_count = 0; // we'll use to track the index in the array of structs
	
	// 1. open the file
	FILE* input_stream = fopen("students.csv", "r"); 

	// 2. read the title/header line in the file stream so that we can move onto
	//    the first data line/record in the file.
	fgets(line, 150, input_stream);

	// 3. read the next line from the file until we reach the end
	while (fgets(line, 150, input_stream) != NULL) // fgets () returns NULL if not more lines to read
	{
		// we have the next line from the file in our array named "line"
		// 4. find and separate the last name in the array and store in
		// the last name field in the appropriate position in the array of
		// structs
		strcpy(arr_students[line_count].last, strtok(line, ","));

		// 5. find and separate the first name in the array and store in
		// the first name field in the appropriate position in the array of
		// structs
		strcpy(arr_students[line_count].first, strtok(NULL, ",")); // use NULL to continue w/ same array

		// 6. find and separate the id number in the array and store in
		// the id field in the appropriate position in the array of
		// structs. The substring/token for id must be converted to an integer.
		arr_students[line_count].id = atoi(strtok(NULL, ",")); // use NULL to continue w/ same array

		// 7. find and separate the gpa in the array and store in
		// the gpa field in the appropriate position in the array of
		// structs. The substring/token for gpa must be converted to a
		// floating-point number.
		arr_students[line_count].gpa = atof(strtok(NULL, "\n")); // use NULL to continue w/ same array
		                                                 // use "\n" for delimiter 

		// 8. go to the next record in the array of structs
		++line_count;
	}

	// 9. print out all of the records stored in the array of structs
	puts("Before bubble sort:");
    print_records(arr_students, line_count);
    bubble_sort(arr_students, line_count);
    puts("After bubble sort:");
    print_records(arr_students, line_count);

	// 10. close the file stream
	fclose(input_stream);

    return 0;
}