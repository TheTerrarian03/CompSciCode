#include "functions.h"

// read/write to file functions
int checkFitbitDataPresent() {
    FILE *stream = fopen(INPUT_FILE, "r");

    if (stream != NULL) {
        fclose(stream);
        return 1;
    }
    
    printf("ERROR: The file `FitbitData.csv` doesn't exist relative to this program.\nPlease place the data here and try again.");
    return 0;
}

int duplicateMinuteRecord(FitbitData data[DATA_LEN], char *minute, int numRecords) {
    // return 1 if minute has already been recorded
    for (int i=0; i < numRecords; i++) {
        if (strcmp(data[i].minute, minute) == 0) return 1;
    }
    
    return 0;
}

void writeResults() {
    // header line: "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep"

    // data for those values

    // fitbit first 2 lines

    // fitbit cleansed data

    // for all data in the array

        // convert data to string

        // write string to file
    
    // close output file
}

void validEntries(char line[MAX_LINE_CHARS], int valids[8]) {
    int i=0, v=0;
    int lastComma = 0;

    // Initialize the valids array to 0
    for (int j = 0; j < 8; j++) {
        valids[j] = 0;
    }

    while (v < 8 && i <= strlen(line)) {
        if (line[i] == '\n' || line[i] == ',' || i == strlen(line) || line[i] == '\0') {
            if ((i - lastComma) > 1) valids[v] = 1;
            lastComma = i;
            v++;
        }
        i++;
    }

    // I was struggling with an edge case, had to use ChatGPT to help me out here;
    // It had to to with handling weird endings of lines from fgets...
    // Handle the case where the last column is empty due to a trailing comma
    if (lastComma == i - 1) {
        valids[v - 1] = 0; // Ensure the last column is marked as invalid if empty
    }
}

char *parseLine(char *target, char line[MAX_LINE_CHARS], FitbitData *newRecord) {
    // valid entries, used to skipping empty columns and multiple commas
    int valids[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    validEntries(line, valids);

    // printf("Valids: %d %d %d %d %d %d %d %d\n", valids[0], valids[1], valids[2], valids[3], valids[4], valids[5], valids[6], valids[7]);

    // assuming target is always filled in data    
    char *readTarget = strtok(line, ",");

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
        newRecord->heartRate = -1;
    }

    // steps
    if (valids[6]) {
        newRecord->steps = atoi(strtok(NULL, ","));
    } else {
        newRecord->steps = -1;
    }

    // sleep level
    if (valids[7]) {
        switch (atoi(strtok(NULL, ","))) {
            case 1:  newRecord->sleepLevel = ASLEEP;      break;
            case 2:  newRecord->sleepLevel = AWAKE;       break;
            case 3:  newRecord->sleepLevel = REALLYAWAKE; break;
            default: newRecord->sleepLevel = NONE;
        }
    } else {
        newRecord->sleepLevel = NONE;
    }

    return readTarget;
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
    fgets(line, sizeof(line), infile);  // get second line

    int numRecords = 0;
    
    while(fgets(line, sizeof(line), infile) != NULL) {
        // read line
        // printf("Line: %s", line);

        // new var to pass to parse
        FitbitData newRecord = {};

        char *readTarget = parseLine(target, line, &newRecord);

        // printf("%s\n", newRecord.minute);

        // skip if targets don't match
        if (strcmp(readTarget, target) != 0) continue;

        // skip if minute has already been recorded
        if (duplicateMinuteRecord(data, newRecord.minute, numRecords)) {
            printf("Found duplicate minute: %s\n", newRecord.minute);
            continue;
        }

        // set new var's values to it's spot in the array
        strcpy(data->patient, readTarget);
        strcpy(data->minute, newRecord.minute);
        data->calories = newRecord.calories;
        data->distance = newRecord.distance;
        data->floors = newRecord.floors;
        data->heartRate = newRecord.heartRate;
        data->steps = newRecord.steps;
        data->sleepLevel = newRecord.sleepLevel;
    
        // printf("Info for record %s:\n- %s\n- %lf\n- %d\n- %d\n- %d\n- %d\n- %d\n", target, newRecord.minute, newRecord.calories, newRecord.distance, newRecord.floors, newRecord.heartRate, newRecord.steps, newRecord.sleepLevel);

        numRecords++;
    };

    printf("Found %d total valid records.\n", numRecords);

    // close file
    fclose(infile);

    return numRecords;
}

void calculateResults(FitbitData data[DATA_LEN], Results *result, int numRecords) {
    // variables to use throughout this function
    int totalHeartRate = 0;
    int maxSteps = 0;
    
    // walk the array and update info on totals and averages
    for (int i=0; i < numRecords; i++) {
        // calories, distance, floors, and steps
        result->caloriesBurned += data[i].calories != -1 ? data[i].calories : 0;
        result->distanceWalked += data[i].distance != -1 ? data[i].distance : 0;
        result->floorsWalked   += data[i].floors   != -1 ? data[i].floors   : 0;
        result->stepsTaken     += data[i].steps    != -1 ? data[i].steps    : 0;

        // local heartrate total
        totalHeartRate += data[i].heartRate != -1 ? data[i].heartRate : 0;

        // update max steps
        if (data[i].steps > result->maxSteps) result->maxSteps = data[i].steps;
    }

    // average heartrate
    result->averageHeartRate = totalHeartRate / numRecords;

    // walk the array again and find the worst sleep range
    // ... seperated from previous for loop for readability
    char *startMin = NULL;
    int worstSleepTotal = 0, tmpTotal = 0;
    for (int i=0; i < numRecords; i++) {
        // if a range isn't being tracked yet
        if (startMin == NULL) {
            if (data[i].sleepLevel > 1) {
                startMin = data[i].minute;
                tmpTotal += data[i].sleepLevel;
                printf("New range being tracked at %s\n", startMin);
            }
        }

        // if a range is being tracked
        else {
            if (data[i].sleepLevel > 1) {
                // continue adding total
                tmpTotal += data[i].sleepLevel;
                printf("Current Worst: %d\n", tmpTotal);
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

    // longest consecutive range of poor sleep

        // 1+ minutes with sleepLevel > 1

        // not length, but sum of sleep levels in that range

        // find starting and ending minutes

        // sleeping hours are 9pm to 8am
}
