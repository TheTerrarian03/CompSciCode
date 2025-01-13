/* Comment
   Block
*/

// Single-line comment

#include "movieUtilities.h"

int main() {
    FILE *inputStream = fopen("movies.csv", "r");
    char line[100] = "";
    Movie records[10] = { {"", -1} };
    int numRecords = 0;

    // did we open the file successfully?
    if (inputStream != NULL) {
        // yes, opened successfully

        fgets(line, 100, inputStream);
        puts(line);

        while (fgets(line, 100, inputStream) != NULL) {  // or !feof(inputStream)
            // Wicked,2024\n\0
            strcpy(records[numRecords].title, strtok(line, ","));
            
            // basically just let strtok work on the last string??
            records[numRecords].year = atoi (strtok(NULL, "\n"));

            printf("records[%d].title: %s\nrecords[%d].year: %d\n",
                numRecords, records[numRecords].title,
                numRecords, records[numRecords].year);

            numRecords++;
        }
    } else {
        printf("Error opening the file!\n\n");
    }

    return 0;
}