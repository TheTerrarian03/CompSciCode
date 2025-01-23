#include "functions.h"

int main() {
    // variables
    FitbitData data[DATA_LEN] = {};
    int numRecords = 0;
    Results computedResult = {};
    
    // make sure data exists and can be read
    if (checkFitbitDataPresent() != 1) return -1;

    // welcome screen
    printf("-- [Fitbit Data Analyzer v2.4 or something] --\n");
    printf("\nReading data and finding invalid entries...\n");

    // read and clean data
    numRecords = readAndCleanData(data);

    printf("\nSuccess! Found %d total valid records.\n", numRecords);

    // calculate results
    calculateResults(data, &computedResult, numRecords);

    // output to terminal
    printf("\nHere is a summary of your Fitbit Stats:\n");
    printf("------------------------------------------------\n");
    printf("- Calories burned:             %.2lf\n- Distance walked (mi):        %.2lf\n- Floors climbed:              %d\n- Steps taken:                 %d\n- Average heart rate:          %.1lf\n- Max steps taken in a minute: %d\n- Worst sleep at times:        %s-%s\n",  // I am sorry for this horribly long line and I'm just making it longer by writing this comment please stop m-
        computedResult.caloriesBurned,
        computedResult.distanceWalked,
        computedResult.floorsWalked,
        computedResult.stepsTaken,
        computedResult.averageHeartRate,
        computedResult.maxSteps,
        computedResult.minuteStart,
        computedResult.minuteEnd);
    printf("------------------------------------------------\n");

    // write results to output file
    writeResults(data, computedResult, numRecords);

    // show user which file the results are in
    printf("\n> Successfully wrote results to `%s`!\n", OUTPUT_FILE);

    return 0;
}
