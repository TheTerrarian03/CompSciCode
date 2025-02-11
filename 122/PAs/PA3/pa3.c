/*
- Name: Logan Meyers
- TA: Martin "Double Factorial" Hundrup
- Assignment: PA 3
- [Mostly] Finished: 02/10/2025
- Description: Digital Music Manager!

- File: pa3.c
- Description: definitions for those main pa3 functions
*/

#include "pa3.h"

/* ----- Menu Functions ----- */

int main_menu() {
    printf("Please enter what you'd like to do with your music:\n\
    1  - Load music to file\n\
    2  - Store music to file\n\
    3  - Display the songs currently loaded\n\
    4  - Insert a song\n\
    5  - Delete a song\n\
    6  - Edit a song\n\
    7  - Sort songs\n\
    8  - Rate a song\n\
    9  - Play songs\n\
    10 - Shuffle songs\n\
    11 - Exit\n");

    return get_pos_int_range_loop("> ", 1, 11);
}
int load_menu(Node **pList) {
    // open file
    FILE *infile = fopen(PLAYLIST_FILE, "r");

    // check for success MARTIN LOOK HERE haha
    if (infile == NULL) {
        printf("There was an error trying to read your file!\nPlease make sure `%s` exists.", PLAYLIST_FILE);
        return 0;
    }

    // delete existing list if there is one,
    // we want to overwrite it
    destroy_list(pList);

    // read lines and put song in the list
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), infile) != NULL) {
        Record new_record;

        record_from_line(&new_record, line);
        
        insert_front(pList, new_record);
    }

    return 1;
}
void store_menu(Node *pList) {
    // make sure there is data to write
    if (pList == NULL || get_list_length(pList) == 0) {
        printf("You have no songs loaded! Canceling store operation.\n");
        return;
    }

    // open the file as write, which would create the file if it
    // doesn't exist MARTIN haha
    FILE *outfile = fopen(PLAYLIST_FILE, "w");

    // write records to file
    while (pList != NULL) {
        store_song_to_playlist(pList->data, outfile);
        pList = pList->pNext;
    }

    fclose(outfile);
}
void display_menu(Node *pList) {
    printf("You have %d songs:\n", get_list_length(pList));

    int cur_num = 1;
    while (pList != NULL) {
        printf("%3d - \"%s\" by \"%s\" [%s]\n        (%s), %d:%d, %d plays, %d/5 rating\n\n",
            cur_num,
            pList->data.song,
            pList->data.artist,
            pList->data.album,
            pList->data.genre,
            pList->data.length.minutes,
            pList->data.length.seconds,
            pList->data.num_plays,
            pList->data.rating);
        
        pList = pList->pNext;
        cur_num++;
    }
}
void insert_menu(Node **pList) {
    Record newRecord;
    
    printf("Please enter the values for the attributes for the new song below:\n");
    printf("NOTE: empty strings allowed, but not recommended.\n");

    printf("Artist => ");
    cpy_nstring_if_exist(newRecord.artist, MAX_NAME_LEN);

    printf("Album => ");
    cpy_nstring_if_exist(newRecord.album, MAX_NAME_LEN);

    printf("Song => ");
    cpy_nstring_if_exist(newRecord.song, MAX_NAME_LEN);

    printf("Genre => ");
    cpy_nstring_if_exist(newRecord.genre, MAX_NAME_LEN);

    printf("Duration => ");
    char line[MAX_NAME_LEN] = "";
    cpy_nstring(line, MAX_NAME_LEN);
    if (line[0] != '\n' && line[0] != '\0') {
        int minutes = atoi(strtok(line, ":"));
        int seconds = atoi(strtok(NULL, "\n\0"));

        if (minutes != 0 && seconds != 0) {
            newRecord.length.minutes = minutes;
            newRecord.length.seconds = seconds;
        }
    }

    printf("Times played => ");
    set_int_in_range_if_exist("", &(newRecord.num_plays), 0, INT_MAX);

    printf("Rating (1-5) => ");
    set_int_in_range_if_exist("", &(newRecord.rating), 1, 5);

    insert_front(pList, newRecord);
}
void delete_menu(Node **pList) {
    printf("What song would you like to delete? (Case-sensitive)\n> ");

    char song[MAX_NAME_LEN] = "";
    cpy_nstring(song, MAX_NAME_LEN);

    printf("Got song: %s\n", song);

    // check to see if song exists in playlist
    Node *song_node = get_song_node(*pList, song);
    if (song_node == NULL) {
        printf("That song doesn't exist! Please try deleting another song.\n");
        return;
    }

    printf("Removing...\n");

    int success = remove_song(pList, song);

    if (success) printf("Successfully removed \"%s\"!\n", song);
    else printf("Failed to remove \"%s\", song doesn't exist.\n", song);
}
void edit_menu(Node *pList) {
    printf("!! THIS HAS NOT BEEN IMPLEMENTED AND MAY NOT WORK AT ALL !!\n");

    printf("What artist would you like to seach for? (Case-sensitive)\n> ");

    char artist[MAX_NAME_LEN] = "";
    cpy_nstring(artist, MAX_NAME_LEN);

    printf("Got artist: \"%s\"\n", artist);

    // check to see if artist exists in playlist
    int artist_exists = get_artist_exists(pList, artist);
    if (!artist_exists) {
        printf("That artist doesn't exist! Please try searching by another artist.\n");
        return;
    }

    // show songs that match artist
    int num_matching = print_songs_matching_artist(pList, artist);

    printf("Please enter the number song you'd like to edit (1-%d)\n> ", num_matching);

    int song_num = get_pos_int_range_loop("> ", 1, num_matching);

    Node *song_to_edit = get_nth_song_of_artist(pList, artist, song_num);

    printf("Please enter the new values you'd like for each field below.\n");
    printf("NOTE: These are taken literally and there will be no redos.\n");
    printf("NOTE: entering nothing and just pressing enter will skip and keep current value\n");
    printf("Anything that should be a number but is a character is converted with 0 as default.\n");
    
    printf("Artist => ");
    cpy_nstring_if_exist(song_to_edit->data.artist, MAX_NAME_LEN);

    printf("Album => ");
    cpy_nstring_if_exist(song_to_edit->data.album, MAX_NAME_LEN);

    printf("Song => ");
    cpy_nstring_if_exist(song_to_edit->data.song, MAX_NAME_LEN);

    printf("Genre => ");
    cpy_nstring_if_exist(song_to_edit->data.genre, MAX_NAME_LEN);

    printf("Duration => ");
    char line[MAX_NAME_LEN] = "";
    cpy_nstring(line, MAX_NAME_LEN);
    if (line[0] != '\n' && line[0] != '\0') {
        int minutes = atoi(strtok(line, ":"));
        int seconds = atoi(strtok(NULL, "\n\0"));

        if (minutes != 0 && seconds != 0) {
            song_to_edit->data.length.minutes = minutes;
            song_to_edit->data.length.seconds = seconds;
        }
    }

    printf("Times played => ");
    set_int_in_range_if_exist("", &(song_to_edit->data.num_plays), 0, INT_MAX);

    printf("Rating (1-5) => ");
    set_int_in_range_if_exist("", &(song_to_edit->data.rating), 1, 5);
}
void sort_menu(Node **pList) {
    printf("Which way would you like to sort your music?\n");
    printf("1) Artist (A-Z)\n");
    printf("2) Album (A-Z)\n");
    printf("3) Rating (1-5)\n");
    printf("4) Time played (big -> small)\n");

    int choice = get_pos_int_range_loop("> ", 1, 4);

    printf("Got choice: %d\n", choice);

    switch (choice) {
        case 1: sort_artist(pList); break;
        case 2: sort_album(pList);  break;
        case 3: sort_rating(pList); break;
        case 4: sort_plays(pList);  break;
        default: printf("Invalid, not sorting.\n");
    }
}
void rate_menu(Node **pList) {
    printf("What song would you like to rate? (Case-sensitive)\n> ");

    char song[MAX_NAME_LEN] = "";
    cpy_nstring(song, MAX_NAME_LEN);

    printf("Got song: %s\n", song);

    // check to see if song exists in playlist
    Node *song_node = get_song_node(*pList, song);
    if (song_node == NULL) {
        printf("That song doesn't exist! Please try rating another song.\n");
        return;
    }

    printf("Please enter the rating you'd like to give \"%s\": (1-5)\n", song);
    int rating = get_pos_int_range_loop("> ", 1, 5);

    song_node->data.rating = rating;

    printf("Successfully gave song \"%s\" rating %d.\n", song, rating);
}
void play_menu(Node *pList) {
    printf("Playing %d songs...\n\n", get_list_length(pList));

    while (pList != NULL) {
        play_song(pList);

        putchar('\n');
        pList = pList->pNext;
    }
}
void shuffle_menu(Node *pList) {
    // frequency array of fixed size
    int order[100];
    int list_len = get_list_length(pList);

    // generate unique nums for song order
    for (int i = 1; i <= list_len; i++) {
        int random_number;

        int found = 0;
        do {
            random_number = rand() % list_len + 1; // random number from 1 to list_len

            found = 0;
            for (int j = 0; j < i; j++) {
                if (order[j] == random_number) {
                    found = 1;
                    break;
                }
            }

        } while (found);

        order[i] = random_number;
    }

    // play through all songs, keeping track of current # and node
    int cur_id = 1;
    Node *pCur = pList;

    for (int i=1; i <= list_len; i++) {
        int tgt = order[i];

        while (cur_id < tgt) {
            cur_id++;
            pCur = pCur->pNext;
        }
        while (cur_id > tgt) {
            cur_id--;
            pCur = pCur->pPrev;
        }

        play_song(pCur);
        printf("\n\n");
    }
}

void play_song(Node *pList) {
    printf("Playing \"%s\":\n", pList->data.song);
    
    for (int i=0; i < 10; i++) {
        printf("\r0:00 [");

        for (int j=0; j < 10; j++) {
            if (j <= i) printf("X");
            else printf(" ");
        }
        printf("] %d:%d", pList->data.length.minutes, pList->data.length.seconds);

        fflush(stdout);

#ifdef _WIN32
        Sleep(500);  // sleep for 0.5s on Windows
#else
        sleep(1);  // sleep for 1s on mac/linux
#endif
    }
}

/* ----- File reading/writing ----- */

void store_song_to_playlist(Record song, FILE *outfile) {
    char tmp[MAX_NAME_LEN+2] = "";
    
    // artist
    string_to_file_format(tmp, song.artist);
    fprintf(outfile, "%s,", tmp);

    // album
    string_to_file_format(tmp, song.album);
    fprintf(outfile, "%s,", tmp);

    // song
    string_to_file_format(tmp, song.song);
    fprintf(outfile, "%s,", tmp);

    // genre
    string_to_file_format(tmp, song.genre);
    fprintf(outfile, "%s,", tmp);

    // other num stats
    fprintf(outfile, "%d:%d,%d,%d\n",
        song.length.minutes,
        song.length.seconds,
        song.num_plays,
        song.rating);
}

/* ----- Data Parsing Functions ----- */

void string_to_file_format(char dest[MAX_NAME_LEN+2], char *src) {
    // check if there is a comma in the string to write
    char *comma_pos = strchr(src, ',');
    if (comma_pos) {
        strcpy(dest, "\"");
        strncat(dest, src, MAX_NAME_LEN);
        strcat(dest, "\"");
    } else {
        strncpy(dest, src, MAX_NAME_LEN);
    }
}
// for this function, I had to use a little ChatGPT to help get past some errors I was stuck on.
// originally, I was just using strtok and strcpy but the way strtok works,
// I was unable to get the pointer to the next portion of the line. So, with a little help,
// this is what I've come up with:
char *extract_string(char dest[MAX_NAME_LEN], char *line) {
    char *start = line;

    if (*start == '"') {
        start++;  // move past first quote
        char *end = strchr(start, '"');  // find next ending quote
        if (end) {
            strncpy(dest, start, end - start);  // copy string to dest without quotes
            dest[end - start] = '\0';
            return end + 2;  // return pointer to next character, after quote and comma
        }
    } else {
        char *end = strchr(line, ',');  // find next comma
        if (end) {
            strncpy(dest, start, end - start);  // copy string to dest
            dest[end - start] = '\0';
            return end + 1;  // return pointer to next character, after comma
        }
    }

    // if all else fails, cry, but just return NULL
    return NULL;
}

void record_from_line(Record *to_store, char line[MAX_LINE_LEN]) {
    char artist[MAX_NAME_LEN] = {'\0'}, album[MAX_NAME_LEN] = { '\0' }, song[MAX_NAME_LEN] = { '\0' }, genre[MAX_NAME_LEN] = { '\0' };

    // read artist, album, song, and genre
    char *next = extract_string(to_store->artist, line);
    if (next) next = extract_string(to_store->album, next);
    if (next) next = extract_string(to_store->song, next);
    if (next) next = extract_string(to_store->genre, next);

    // get other number stats
    if (next) {
        Duration len = {.minutes = atoi(strtok(next, ":")),
                        .seconds = atoi(strtok(NULL, ","))};
        to_store->length = len;

        to_store->num_plays = atoi(strtok(NULL, ","));
        to_store->rating = atoi(strtok(NULL, ",\n\0"));
    }
}
