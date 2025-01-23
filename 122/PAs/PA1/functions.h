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

int sleepToInt(Sleep val);

int checkFitbitDataPresent();

int duplicateMinuteRecord(FitbitData data[DATA_LEN], char *minute, int numRecords);

void writeResults();

void validEntries(char line[MAX_LINE_CHARS], int valids[8]);

char *parseLine(char *target, char line[MAX_LINE_CHARS], FitbitData *newRecord);

int readAndCleanData(FitbitData fitbitData[DATA_LEN]);

void calculateResults(FitbitData data[DATA_LEN], Results *result, int numRecords);

#endif