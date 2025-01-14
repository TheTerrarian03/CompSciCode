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

void parseLine(char line[MAX_LINE_CHARS], FitbitData *fitbitData) {
    // target

    // minute string

    // calories

    // distance

    // floors

    // heartrate

    // steps

    // sleep level
}

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

    // read second line
    fgets(line, sizeof(line), infile);

    int numRecords = 0;

    while(!feof(infile));
        // read line
        fgets(line, sizeof(line), infile);

        // new var to pass to parse
        FitbitData newRecord = {};

        parseLine(fitbitData, &newRecord);

        // if target != actual target: continue

        // if newMinuteRecord == 0: continue

        // set new var's values to it's spot in the array
    
    // close file
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
