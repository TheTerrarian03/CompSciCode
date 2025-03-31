#include "List.hpp"
#include "util.hpp"
#include <string>
#include <sstream>

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
};
