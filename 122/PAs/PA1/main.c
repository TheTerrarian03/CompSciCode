#include "functions.h"

int main() {
    // fitbit data array
    FitbitData fitbitData[DATA_LEN] = {};
    
    // make sure data exists and can be read
    if (checkFitbitDataPresent() != 1) return -1;

    // read and clean data
    readAndCleanData(fitbitData);

    // calculate results

    // write results

    // output to terminal
    
    return 0;
}

// read line
// strtok with line for first use
// strtok with NULL for other uses
// strtok will skip commas if they're the first characters being read, so
//   will need to check for the comma at the start of the returned 
// possibly write algorithm to check for missing items
//   keep track of commas in the line

// 1)   clean data first
// 1.1) remove lines not related to the target patient
// 1.2) remove lines that are duplicates (same target, new matching timestamp)
// 1.3) search for missing data and insert -1's for invalid data
// 2)   then use strtok for every line, insert data into struct array
// 3)   perform calculations
// 3.1) for each type, skips -1's