/*
- Name: Logan Meyers
- TA: Martin
- PA: #1
- Date: Jan 22 2025
- Description: Fitbit Data cleaner and analyzer!

- File: functions.h
- Description: Headerfile for the functions.c file
*/

#ifndef FUNCS_H
#define FUNCS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definitions
#define INPUT_FILE "FitbitData.csv"
#define OUTPUT_FILE "Results.csv"
#define DATA_LEN 1440
#define MAX_LINE_CHARS 70
#define FITBIT_STR_DATA_LEN 10

// comment out to disable lines 3 & 4
// being written in the output file
// (the header lines from the original data csv)
// (I was unsure if it was required these be written)
#define WRITE_CLEANED_HEADER_LINES

// type definitions
typedef enum sleep {
    NONE = 0,
    ASLEEP = 1,
    AWAKE = 2,
    REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
    char patient[FITBIT_STR_DATA_LEN];
    char minute[FITBIT_STR_DATA_LEN];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;

// custom type for results, makes passing of these values easier
typedef struct results {
    double caloriesBurned;
    double distanceWalked;
    int floorsWalked;
    int stepsTaken;
    int maxSteps;
    double averageHeartRate;
    char *minuteStart;
    char *minuteEnd;
} Results;

// ----- General Tool Functions ----- //

/*
 * Function: sleepToInt
 * --------------------
 *   Returns the integer value of the Sleep enum
 * 
 *   Returns:
 *   - 0 through 3
*/
int sleepToInt(Sleep val);

/*
 * Function: checkFitbitDataPresent
 * --------------------
 *   Makes sure the defines input file exists
 * 
 *   Returns:
 *   - 0 for fail, 1 for success
*/
int checkFitbitDataPresent();

/*
 * Function: validEntries
 * --------------------
 *   Walks a given line and finds the columns that do and don't have valid data to be read
 * 
 *   Parameters:
 *   - line: line from CSV file to walk and check
 *   - valids: array of 8 ints representing which corresponding columns are valid
*/
void validEntries(char line[MAX_LINE_CHARS], int valids[8]);

// ----- FitbitData-Related Functions ----- //

/*
 * Function: duplicateMinuteRecord
 * --------------------
 *   Terrible O(n) algorithm I made to check if the minute has already been recorded
 * 
 *   Parameters:
 *   - data: the list of FitbitData structs
 *   - minute: the string to check against other records
 *   - numRecords: how many records to check through
 * 
 *   Returns:
 *   - 1 for duplicate, 0 for unique
*/
int duplicateMinuteRecord(FitbitData data[DATA_LEN], char *minute, int numRecords);

/*
 * Function: writeResults
 * --------------------
 *   Write out the results and cleaned data to the defined output file
 * 
 *   Parameters:
 *   - data: the list of FitbitData structs
 *   - minute: the string to check against other records
 *   - numRecords: how many records to check through
*/
void writeResults(FitbitData data[DATA_LEN], Results result, int numRecords);



/*
 * Function: parseLine
 * --------------------
 *   Parses a given line and assigns the correct values to the newRecord; read-in values if valid, defaults if not
 * 
 *   Parameters:
 *   - line: line from CSV file to parse data from
 *   - newRecord: pointer to the struct you want to assign read data to
*/
void parseLine(char line[MAX_LINE_CHARS], FitbitData *newRecord);

/*
 * Function: readAndCleanData
 * --------------------
 *   Reads through the entire defined input file and populates the given array with the data
 * 
 *   Parameters:
 *   - data: the array of FitbitData structs to assign values to
 * 
 *   Returns:
 *   - how many (valid) records were read
*/
int readAndCleanData(FitbitData data[DATA_LEN]);

/*
 * Function: calculateResults
 * --------------------
 *   Takes the populated data and finds some cool info about it
 * 
 *   Parameters:
 *   - data: the list of FitbitData structs to analyze
 *   - result: pointer to the struct for results you want to store findings to
 *   - numRecords: how many records have been read/are in the array
*/
void calculateResults(FitbitData data[DATA_LEN], Results *result, int numRecords);

#endif
