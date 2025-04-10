/*
- Name: Logan Meyers
- TA: Martin Hundrup
- Date Finished: 04-09-2025
- Program: Student Absence Manager

- File: RecordManager.hpp
- What: Header file for my Record Manager wrapper
        has defines, class declaration, function declarations, and includes
*/

#pragma once

#include "List.hpp"
#include "util.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <format>
#include <vector>

#define CLASS_LIST_FILE "classList.csv"
#define MASTER_LIST_FILE "masterList.csv"
#define MASTER_LIST_HEADER_STRING ",ID,Name,Email,Units,Program,Level,NumAbsences,AbsenceDates..."
#define REPORT_ALL_FILE "All Report.txt"
#define REPORT_SPECIFIC_FILE "Specific Report.txt"

class RecordManager {

public:
    /* ----- Constructors & Destructors ----- */
    RecordManager();
    ~RecordManager();

    // Public run function, runs the application and everything involved
    void run();

private:
    // list data member
    List<Data> records;

    /* ----- Main- & Sub-Menu Functions----- */
    // main menu, offers options 1-7
    int mainMenu();
    // report menu, offers options 1-3 
    int reportMenu();
    // edit menu, offers options 1-5
    int editMenu();
    // asks user for the min amount of absences, and returns the int
    int minAbsenceMenu();
    
    /* ----- "Perform" Functions ----- */
    // based on what the user selected, run the appropriate abstracted mm function
    bool performMainMenuOption(int option);
    // generate a report for all students
    bool performAllReport();
    // generate a report for student with the min absence amount or more
    bool performSpecificReport(int minAbsences);

    /* ----- Abstracted Main Menu Functions ----- */
    // import from the class list csv
    bool mmImport();
    // import from the master list csv
    bool mmLoadMaster();
    // store to (overwrite) the master list csv
    bool mmStoreMaster();
    // ask for input for each user for if they were absent, and mark it
    bool mmMarkAbsences();
    // calls the appropriate abstracted edit function
    bool mmEditAbsences();
    // asks for type of report to generate, and calls the appropriate perform function
    bool mmGenReports();

    /* ----- Abstracted Edit Functions ----- */
    // asks for and edits a particular student's attendance
    bool editStudent();
    // removes all duplicated from all student's attendance records
    bool editDuplicates();
    // removes all absences from all students
    bool editClear();
    // removes all absences from all students, for a particular day
    bool editClearDay();

    /* ----- Helper Functions ----- */
    // extract an integer from an istringstream, or the error value from stoi
    int getIntFromISS(std::istringstream &from);
    // extract a double from an istringstream, or the error value from stod
    double getDoubleFromISS(std::istringstream &from);
    // extract a string from an istringstream, and removes newline and carriage return
    std::string getStrFromISS(std::istringstream &from);
};
