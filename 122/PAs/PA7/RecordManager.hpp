#include "List.hpp"
#include "util.hpp"
#include <string>
#include <sstream>
#include <fstream>

#define CLASS_LIST_FILE "classList.csv"
#define MASTER_LIST_FILE "masterList.csv"
#define MASTER_LIST_HEADER_STRING ",ID,Name,Email,Units,Program,Level,NumAbsences,AbsenceDates..."

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
    Data editMenu();
    
    // perform functions
    bool performMainMenuOption(int option);
    bool performReport(int type);

    // abstracted main menu functions
    bool mmImport();
    bool mmLoadMaster();
    bool mmStoreMaster();
    bool markAbsences();
    bool mmApplyEdit(Data newData);
    bool mmGenReports();

    // helper functions
    int getIntFromISS(std::istringstream &from);
    double getDoubleFromISS(std::istringstream &from);
    std::string getStrFromISS(std::istringstream &from);
};
