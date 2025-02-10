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
    9  - Play a song\n\
    10 - Shuffle songs\n\
    11 - Exit\n> ");

    int choice = 0;

    while (choice == 0) {
        int result = scanf("%d", &choice);

        if (result > 0) break;

        clear_buffer();

        printf("Invalid input! Try again:\n> ");
    }

    return choice;
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
    char line[MAX_LINE_LEN] = {};
    while (fgets(line, sizeof(line), infile) != NULL) {
        Record new_record = {};

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
// void insert_menu();
// void delete_menu();
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

    int song_num = 0;

    while (song_num < 1 || song_num > num_matching) {
        int result = scanf("%d", &song_num);

        if (result > 0 && song_num >= 1 && song_num <= num_matching) break;

        if (result > 0) {
            printf("Number out of range! Try again:\n> ");
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Invalid input! Try again:\n> ");
    }

    Node *song_to_edit = get_nth_song_of_artist(pList, artist, song_num);

    printf("Please enter the new values you'd like for each field below.\n");
    printf("NOTE: These are taken literally and there will be no redos.\n");
    printf("NOTE: entering nothing and just pressing enter will skip and keep current value\n");
    printf("Anything that should be a number but is a character is converted with 0 as default.\n");

    char input[MAX_NAME_LEN] = "";
    
    printf("Artist => ");
    cpy_nstring_if_exist(song_to_edit->data.artist, MAX_NAME_LEN);
    printf("Artist: %s\n", song_to_edit->data.artist);
    printf("Album => ");
    cpy_nstring_if_exist(song_to_edit->data.album, MAX_NAME_LEN);
    printf("Album: %s\n", song_to_edit->data.album);
    printf("Song => ");
    cpy_nstring_if_exist(song_to_edit->data.song, MAX_NAME_LEN);
    printf("Genre => ");
    cpy_nstring_if_exist(song_to_edit->data.genre, MAX_NAME_LEN);

    printf("Times played => ");
    set_int_in_range_if_exist(&(song_to_edit->data.num_plays), 0, __INT32_MAX__);

    printf("Rating (1-5) => ");
    set_int_in_range_if_exist(&(song_to_edit->data.rating), 1, 5);
}
// void sort_menu();
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

    printf("Please enter the rating you'd like to give \"%s\": (1-5)\n> ", song);
    int rating = 0;

    while (rating < 1 || rating > 5) {
        int result = scanf("%d", &rating);

        if (result > 0 && rating >= 1 && rating <= 5) break;

        if (result > 0) {
            printf("Rating out of range! Try again:\n> ");
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Invalid input! Try again:\n> ");
    }

    song_node->data.rating = rating;

    printf("Successfully gave song \"%s\" rating %d.\n", song, rating);
}
void play_menu();
// void shuffle_menu();
void exit_menu();

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
            return end + 2;  // return pointer to next character, after quote and comma
        }
    } else {
        char *end = strchr(line, ',');  // find next comma
        if (end) {
            strncpy(dest, start, end - start);  // copy string to dest
            return end + 1;  // return pointer to next character, after comma
        }
    }

    // if all else fails, cry, but just return NULL
    return NULL;
}

void record_from_line(Record *to_store, char line[MAX_LINE_LEN]) {
    char artist[MAX_NAME_LEN] = "", album[MAX_NAME_LEN] = "", song[MAX_NAME_LEN] = "", genre[MAX_NAME_LEN] = "";

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