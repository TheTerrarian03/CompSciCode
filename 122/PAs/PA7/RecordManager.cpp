#include "RecordManager.hpp"

// constructor and destructor
RecordManager::RecordManager() : records() {}
RecordManager::~RecordManager() {}

// main run function
void RecordManager::run() {
    for (int option = mainMenu(); option != 7; option = mainMenu()) {
        if (option > 7 || option < 0) std::cout << "Invalid input! Enter a number 1-7!" << std::endl;
        else if (option == 0) std::cout << "Invalid input! Only enter numbers!" << std::endl;
        else performMainMenuOption(option);
    }
}

// main menu functions
int RecordManager::mainMenu() {
    int option;
    std::string input;

    // prompt
    std::cout << "enter number: ";

    // read whole cin line and extract int option from it if possible
    std::getline(std::cin, input);
    std::istringstream iss(input);

    // return option chosen or 0 for fail
    if (iss >> option) return option;
    else return 0;
}
int RecordManager::reportMenu() {
    return 0;
}
Data RecordManager::editMenu() {
    return Data();
}

// perform functions
bool RecordManager::performMainMenuOption(int option) {
    clearConsole();
    
    switch (option) {
        case 1: return mmImport()
    }
}
bool RecordManager::performReport(int type) {
    return true;
}


// abstracted main menu functions
bool RecordManager::mmImport() {}
bool RecordManager::mmLoadMaster() {}
bool RecordManager::mmStoreMaster() {}
bool RecordManager::markAbsences() {}
bool RecordManager::mmApplyEdit(Data newData) {}
bool RecordManager::mmGenReports() {}
