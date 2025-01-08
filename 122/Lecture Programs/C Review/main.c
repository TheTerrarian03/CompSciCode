/* Comment
   Block
*/

// Single-line comment

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // printf, scanf
#include <string.h>  // strcat, strcpy, strlen, strtod, strtok

int main() {
    FILE *inputStream = fopen("movies.csv", "r");
    char line[100] = "";

    // did we open the file successfully?
    if (inputStream != NULL) {
        // yes, opened successfully

        fgets(line, 100, inputStream);
        puts(line);
    } else {

    }

    return 0;
}