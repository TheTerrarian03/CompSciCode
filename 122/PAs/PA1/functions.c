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

int duplicateMinuteRecord(FitbitData fitbitData[DATA_LEN]) {
    // return 1 if minute has already been recorded

    // return 0 if minute has not been recorded
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

    while (v < 8) {
        if (line[i] == (v == 7) ? '\n' : ',') {
            printf("looking for: '%c'\n", (v == 8) ? '\n' : ',');
            if (i - lastComma > 1) valids[v] = 1;
            lastComma = i;
            v++;
        }

        i++;
    }
}

char *parseLine(char *target, char line[MAX_LINE_CHARS], FitbitData *newRecord) {
    // target
    int valids[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // validEntries(line, valids);

    // printf("Valids: %d %d %d %d %d %d %d %d\n", valids[0], valids[1], valids[2], valids[3], valids[4], valids[5], valids[6], valids[7]);

    // char *readTarget = strtok(line, ",");
    // printf("Got target: %s\n", readTarget);

    // minute string

    // calories

    // distance

    // floors

    // heartrate

    // steps

    // sleep level
}

// for some reason this reads double the 2nd-to-last line if the last is a newline??
void readAndCleanData(FitbitData fitbitData[DATA_LEN]) {
    // open input file
    FILE *infile = fopen(INPUT_FILE, "r");
    
    // read first line
    char line[MAX_LINE_CHARS] = {};
    
    fgets(line, sizeof(line), infile);  // get first line

    // extract target
    char target[10] = {};
    strtok(line, ",");                        // read past 'Target: ,'
    strcpy(target, strtok(NULL, ","));              // copy the value after that into target, like "12cx7"

    // read second line, won't do anything with it, just header data
    fgets(line, sizeof(line), infile);  // get second line

    int numRecords = 0;
    
    while(fgets(line, sizeof(line), infile) != NULL) {
        // read line
        printf("Line: %s", line);

        // new var to pass to parse
        FitbitData newRecord = {};

        char *readTarget = parseLine(target, line, &newRecord);

        // if target != actual target: continue

        // if newMinuteRecord == 0: continue

        // set new var's values to it's spot in the array
    
        // printf("Info for record #%d:\n- %d\n- %d\n- %d\n- %d\n- %d\n- %d\n- %d\n", target, newRecord.minute, newRecord.calories, newRecord.distance, newRecord.floors, newRecord.heartRate, newRecord.steps, newRecord.sleepLevel);

    // close file
    };
}

void calculateResults() {
    // total calories

    // distance walked

    // floors walked

    // steps taken

    // average heartrate

    // latest max steps in one minute

    // longest consecutive range of poor sleep

        // 1+ minutes with sleepLevel > 1

        // not length, but sum of sleep levels in that range

        // find starting and ending minutes

        // sleeping hours are 9pm to 8am
}
