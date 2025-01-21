#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct musicRecord {
    char songTitle[75];
    int timesPlayed;
    double avgRating;
} MusicRecord;

int fileLineParser(FILE *inputFileStream, MusicRecord arrMusicRecords[MAX_RECORDS]);

int main() {
    MusicRecord records[MAX_RECORDS] = {};
    FILE *infile = fopen("data.csv", "r");

    int numRead = fileLineParser(infile, records);

    for (int i=0; i < numRead; i++) {
        printf("%d: %s (%d plays, %.1lf average rating)\n", i, records[i].songTitle, records[i].timesPlayed, records[i].avgRating);
    }
}

int fileLineParser(FILE *inputFileStream, MusicRecord arrMusicRecords[MAX_RECORDS]) {
    char line[300] = {};
    int recordsRead = 0;

    // if there was a header line, this would read & skip it
    // fgets(line, sizeof(line), inputFileStream);

    // loop to parse and copy data
    while (fgets(line, sizeof(line), inputFileStream) != NULL) {
        // Check if we have reached the maximum number of records
        if (recordsRead >= MAX_RECORDS) {
            break;
        }

        // parse and copy into the fields
        strncpy(arrMusicRecords[recordsRead].songTitle, strtok(line, ","), 75);
        arrMusicRecords[recordsRead].timesPlayed = atoi(strtok(NULL, ","));
        arrMusicRecords[recordsRead].avgRating = atof(strtok(NULL, "\n"));

        // inc records
        recordsRead++;
    }

    return recordsRead;
}
