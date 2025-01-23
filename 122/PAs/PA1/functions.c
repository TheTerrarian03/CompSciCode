/*
- Name: Logan Meyers
- TA: Martin
- PA: #1
- Date: Jan 22 2025
- Description: Fitbit Data cleaner and analyzer!

- File: functions.c
- Description: All functions to handle the fitbit data, plus file operations
*/

#include "functions.h"

// ----- General Tool Functions ----- //

int sleepToInt(Sleep val) {
    switch (val) {
        case ASLEEP:      return 1; break;
        case AWAKE:       return 2; break;
        case REALLYAWAKE: return 3; break;
        default: return 0;
    }
    return 0;
}

// read/write to file functions
int checkFitbitDataPresent() {
    FILE *stream = fopen(INPUT_FILE, "r");

    if (stream != NULL) {
        fclose(stream);
        return 1;
    }
    
    // could replace with a fprintf(sterr, ...) like martin showed
    printf("ERROR: The file `FitbitData.csv` doesn't exist relative to this program.\nPlease place the data here and try again.");
    return 0;
}

void validEntries(char line[MAX_LINE_CHARS], int valids[8]) {
    int i=0, v=0;
    int lastComma = 0;

    // Initialize the valids array to 0
    for (int j = 0; j < 8; j++) {
        valids[j] = 0;
    }

    // walk the line and find which values are missing data
    while (v < 8 && i <= strlen(line)) {
        if (line[i] == '\n' || line[i] == ',' || i == strlen(line) || line[i] == '\0') {
            if ((i - lastComma) > 1) valids[v] = 1;
            lastComma = i;
            v++;
        }
        i++;
    }
}

// ----- FitbitData-Related Functions ----- //

int duplicateMinuteRecord(FitbitData data[DATA_LEN], char *minute, int numRecords) {
    for (int i=0; i < numRecords; i++) {
        if (strcmp(data[i].minute, minute) == 0) return 1;
    }
    
    return 0;
}

void writeResults(FitbitData data[DATA_LEN], Results result, int numRecords) {
    FILE *outfile = fopen(OUTPUT_FILE, "w");
    
    // header line for file
    fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");

    // data for those values
    fprintf(outfile, "%lf,%lf,%d,%d,%lf,%d,%s-%s\n",
        result.caloriesBurned,
        result.distanceWalked,
        result.floorsWalked,
        result.stepsTaken,
        result.averageHeartRate,
        result.maxSteps,
        result.minuteStart,
        result.minuteEnd);

    // write header lines from the original file if specified
#ifdef WRITE_CLEANED_HEADER_LINES
    fprintf(outfile, "Target:,12cx7,,,,,,\n");
    fprintf(outfile, "Patient,minute,calories,distance,floors,heart,steps,sleep_level");
#endif

    // fitbit cleansed data
    for (int i=0; i < numRecords; i++) {
        fprintf(outfile, "\n%s,%s,%lf,%lf,%d,%d,%d,%d",
            data[i].patient,
            data[i].minute,
            data[i].calories,
            data[i].distance,
            data[i].floors,
            data[i].heartRate,
            data[i].steps,
            sleepToInt(data[i].sleepLevel));
    }
    
    fclose(outfile);
}

void parseLine(char line[MAX_LINE_CHARS], FitbitData *newRecord) {
    // valid entries, used to skipping empty columns and multiple commas
    int valids[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    validEntries(line, valids);

    // assuming target is always filled in data    
    strcpy(newRecord->patient, strtok(line, ","));

    // minute string
    if (valids[1]) {
        strcpy(newRecord->minute, strtok(NULL, ","));
    } else {
        strcpy(newRecord->minute, "");
    }

    // calories
    if (valids[2]) {
        newRecord->calories = atof(strtok(NULL, ","));
    } else {
        newRecord->calories = -1;
    }

    // distance
    if (valids[3]) {
        newRecord->distance = atof(strtok(NULL, ","));
    } else {
        newRecord->distance = -1;
    }

    // floors
    if (valids[4]) {
        newRecord->floors = atoi(strtok(NULL, ","));
    } else {
        newRecord->floors = -1;
    }

    // heartrate
    if (valids[5]) {
        newRecord->heartRate = atoi(strtok(NULL, ","));
    } else {
        newRecord->heartRate = 0;
    }

    // steps
    if (valids[6]) {
        newRecord->steps = atoi(strtok(NULL, ","));
    } else {
        newRecord->steps = -1;
    }

    // sleep level
    // checking for valid doesn't always work here for some reason,
    // but it still reads the data just fine
    if (valids[7]) {
        switch (atoi(strtok(NULL, "\n"))) {
            case 1:  newRecord->sleepLevel = ASLEEP;      break;
            case 2:  newRecord->sleepLevel = AWAKE;       break;
            case 3:  newRecord->sleepLevel = REALLYAWAKE; break;
            default: newRecord->sleepLevel = NONE;
        }
    } else {
        newRecord->sleepLevel = NONE;
    }
}

int readAndCleanData(FitbitData data[DATA_LEN]) {
    // open input file
    FILE *infile = fopen(INPUT_FILE, "r");
    
    // read first line
    char line[MAX_LINE_CHARS] = {};
    
    fgets(line, sizeof(line), infile);  // get first line

    // extract target
    char target[10] = {};
    strtok(line, ",");  // read past 'Target: ,'
    strcpy(target, strtok(NULL, ","));  // copy the value after that into target, like "12cx7"

    // read second line, won't do anything with it, just header data
    fgets(line, sizeof(line), infile);

    int numRecords = 0;
    
    while(fgets(line, sizeof(line), infile) != NULL) {
        // new var to pass to parse
        FitbitData newRecord = {};

        parseLine(line, &newRecord);

        // skip if targets don't match
        if (strcmp(newRecord.patient, target) != 0) {
            printf("> Found non-matching user: %s\n", newRecord.patient);
            continue;
        }

        // skip if minute has already been recorded
        if (duplicateMinuteRecord(data, newRecord.minute, numRecords)) {
            printf("> Found duplicate minute: %s\n", newRecord.minute);
            continue;
        }

        // set new var's values to it's spot in the array
        strcpy(data[numRecords].patient, newRecord.patient);
        strcpy(data[numRecords].minute, newRecord.minute);
        data[numRecords].calories = newRecord.calories;
        data[numRecords].distance = newRecord.distance;
        data[numRecords].floors = newRecord.floors;
        data[numRecords].heartRate = newRecord.heartRate;
        data[numRecords].steps = newRecord.steps;
        data[numRecords].sleepLevel = newRecord.sleepLevel;
    
        numRecords++;
    };

    // close file
    fclose(infile);

    return numRecords;
}

void calculateResults(FitbitData data[DATA_LEN], Results *result, int numRecords) {
    // variables to use throughout this function
    double totalHeartRate = 0.0;
    int maxSteps = 0, numHeartRates = 0;

    // walk the array and update info on totals and averages
    for (int i=0; i < numRecords; i++) {
        // calories, distance, floors, and steps
        result->caloriesBurned += data[i].calories != -1 ? data[i].calories : 0;
        result->distanceWalked += data[i].distance != -1 ? data[i].distance : 0;
        result->floorsWalked   += data[i].floors   != -1 ? data[i].floors   : 0;
        result->stepsTaken     += data[i].steps    != -1 ? data[i].steps    : 0;

        // local heartrate total
        if (data[i].heartRate > 0) {
            totalHeartRate += data[i].heartRate;
            numHeartRates++;
        }

        // update max steps
        if (data[i].steps > result->maxSteps) result->maxSteps = data[i].steps;
    }

    // calc average heartrate
    result->averageHeartRate = totalHeartRate / numHeartRates;

    // walk the array again and find the worst sleep range
    // ... seperated from previous for loop for readability
    char *startMin = NULL;
    int worstSleepTotal = 0, tmpTotal = 0;
    for (int i=0; i < numRecords; i++) {
        // if a range isn't being tracked yet
        if (startMin == NULL) {
            if (sleepToInt(data[i].sleepLevel) > 1) {
                // start tracking
                startMin = data[i].minute;
                tmpTotal += sleepToInt(data[i].sleepLevel);
            }
        }

        // if a range is being tracked
        else {
            if (sleepToInt(data[i].sleepLevel) > 1) {
                // continue adding total
                tmpTotal += sleepToInt(data[i].sleepLevel);
            } else {
                // break found, stop and record
                if (tmpTotal > worstSleepTotal) {
                    worstSleepTotal = tmpTotal;
                    result->minuteStart = startMin;
                    result->minuteEnd = data[i-1].minute;
                }

                // reset vals
                startMin = NULL;
                tmpTotal = 0;
            }
        }
    }
}
