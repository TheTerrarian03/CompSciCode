#ifndef FUNCS_H
#define FUNCS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definitions
#define INPUT_FILE "FitbitData.csv"
#define CLEAN_FILE "FitbitDataCleaned.csv"
#define OUTPUT_FILE "Results.csv"
#define DATA_LEN 1440
#define MAX_LINE_CHARS 64

// type definitions
typedef enum sleep {
    NONE = 0,
    ASLEEP = 1,
    AWAKE = 2,
    REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;

// read/write to file functions
int checkFitbitDataPresent();

int duplicateMinuteRecord(FitbitData fitbitData[DATA_LEN]);

void writeResults();

void parseLine(char line[MAX_LINE_CHARS], FitbitData *fitbitData);

void readAndCleanData(FitbitData fitbitData[DATA_LEN]);

void calculateResults();

#endif
