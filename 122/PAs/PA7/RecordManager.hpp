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
    // constructor and destructor
    RecordManager();
    ~RecordManager();

    // run function
    void run();

private:
    // list data member
    List<Data> records;

    // main & sub- menu functions
    int mainMenu();
    int reportMenu();
    int minAbsenceMenu();
    int editMenu();
    
    // perform functions
    bool performMainMenuOption(int option);
    bool performAllReport();
    bool performSpecificReport(int minAbsences);

    // abstracted main menu functions
    bool mmImport();
    bool mmLoadMaster();
    bool mmStoreMaster();
    bool mmMarkAbsences();
    bool mmEditAbsences();
    bool mmGenReports();

    // abstracted edit menu functions
    bool editStudent();
    bool editDuplicates();
    bool editClear();
    bool editClearDay();

    // helper functions
    int getIntFromISS(std::istringstream &from);
    double getDoubleFromISS(std::istringstream &from);
    std::string getStrFromISS(std::istringstream &from);
};
