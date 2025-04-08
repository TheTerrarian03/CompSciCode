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
    std::cout << "1. Import course list" << std::endl
        << "2. Load master list" << std::endl
        << "3. Store master list" << std::endl
        << "4. Mark absences" << std::endl
        << "5. Edit absences" << std::endl
        << "6. Generate report" << std::endl
        << "7. Exit" << std::endl
        << "enter number: ";

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
        case 1: return mmImport();
        case 3: return mmStoreMaster();
        case 6: {
            records.printList();
            return true;
            break;
        }
    }

    return false;
}
bool RecordManager::performReport(int type) {
    return true;
}

// abstracted main menu functions
bool RecordManager::mmImport() {
    // first, clear whatever's in the current list
    records.deleteList();

    // then, try to open file and exit if fail
    std::ifstream infile("classList.csv");

    if (!infile.is_open()) {
        std::cerr << "Failed to open `classList.csv` file! Could not read records." << std::endl;
        return false;
    }

    // then, read from classList until no more lines
    std::string line;

    getline(infile, line);  // discard first header line

    // this is admittedly a horrible way of doing this,
    // this really needs more error handling...
    // but assuming the input file is always formatted correctly,
    // (which andy said it should be), then we cool
    while(getline(infile, line)) {
        if (line.empty()) {
            std::cout << "Empty record found, skipping..." << std::endl;
            continue;
        }

        Data record = Data();

        // convert line to string stream
        std::istringstream iss(line);

        // read from string stream into values

        record.setRecordNum(getIntFromISS(iss));
        record.setIdNum(getIntFromISS(iss));
        record.setName(getStrFromISS(iss));
        record.setEmail(getStrFromISS(iss));
        if (iss.peek() == 'A') {  // remove AU from credits and set credits to 0
            record.setUnits(0);
            iss.get();
            iss.get();
            iss.get();
        } else {  // otherwise just extract value
            record.setUnits(getDoubleFromISS(iss));
        }
        record.setProgram(getStrFromISS(iss));
        record.setLevel(getStrFromISS(iss));  // getting string here, still has newline

        if (record.validRecord()) {
            records.insertAtFront(record);
        }
    }

    infile.close();

    return true;
}
bool RecordManager::mmLoadMaster() {}
bool RecordManager::mmStoreMaster() {
    // try to open file to export to
    std::ofstream outfile("masterList.csv");

    if (!outfile.is_open()) {
        std::cerr << "Failed to open or create `masterList.csv` file! Could not store master list." << std::endl;
    }

    // write header line
    outfile << ",ID,Name,Email,Units,Program,Level,NumAbsences,AbsenceDates..." << std::endl;
    
    // made copy of records so they can be popped and written
    List<Data> copy(records);

    // write records to file
    while (!copy.isEmpty()) {
        Data top = copy.pop();
        
        // main data
        outfile << top.getRecordNum() << ","
            << top.getIdNum() << ","
            << '"' << top.getName() << "\","
            << top.getEmail() << ","
            << top.getUnits() << ","
            << top.getProgram() << ","
            << top.getLevel() << ","
            << top.getAbsences();
        
        // stack of absences
        std::stack<std::string> absences = top.getAbsenceDates();

        while (!absences.empty()) {
            outfile << "," << absences.top();  // pop and write top date
        }

        outfile << std::endl;
    }

    outfile.close();

    return true;
}
bool RecordManager::markAbsences() {}
bool RecordManager::mmApplyEdit(Data newData) {}
bool RecordManager::mmGenReports() {}

// helper functions
int RecordManager::getIntFromISS(std::istringstream &from) {
    std::string tmp;
    getline(from, tmp, ',');
    return std::stoi(tmp);
}
double RecordManager::getDoubleFromISS(std::istringstream &from) {
    std::string tmp;
    getline(from, tmp, ',');
    return std::stod(tmp);
}
std::string RecordManager::getStrFromISS(std::istringstream &from) {
    std::string tmp;
    
    // if next char is a quote, read until the next quote
    if (from.peek() == '"') {
        from.get();  // read next quote

        getline(from, tmp, '"');
        from.get();
    }
    // otherwise, read until next comma
    else {
        getline(from, tmp, ',');
    }

    // this doesn't seem to work right
    if (!tmp.empty()) {
        while (tmp.back() == '\n' || tmp.back() == '\r') {
            tmp.pop_back();
        }
    }

    // std::cout << "Read str string: '" << tmp << '\'' << std::endl;
    return tmp;
}
