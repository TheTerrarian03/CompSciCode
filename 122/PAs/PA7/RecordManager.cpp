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
        case 2: return mmLoadMaster();
        case 3: return mmStoreMaster();
        case 6: {
            records.printList();
            return true;
            break;
        }
        default: {
            std::cout << "Not implemented!" << std::endl;
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
    std::ifstream infile(CLASS_LIST_FILE);

    if (!infile.is_open()) {
        std::cerr << "Failed to open `" << CLASS_LIST_FILE << "` file! Could not read records." << std::endl;
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
            iss.get();  // 'A'
            iss.get();  // 'U'
            iss.get();  // ','
        } else {  // otherwise just extract value
            record.setUnits(getDoubleFromISS(iss));
        }
        record.setProgram(getStrFromISS(iss));
        record.setLevel(getStrFromISS(iss));

        if (record.validRecord()) {
            records.insertAtFront(record);
        }
    }

    infile.close();

    return true;
}
bool RecordManager::mmLoadMaster() {
    // first, clear list
    records.deleteList();

    // try to open file to read from
    std::ifstream infile(MASTER_LIST_FILE);

    if (!infile.is_open()) {
        std::cerr << "Failed to open `" << MASTER_LIST_FILE << "` file! Could not read master list." << std::endl;
        return false;
    }

    // read header line
    std::string line;
    getline(infile, line);

    // read until no more records
    while(getline(infile, line)) {
        if (line.empty()) {
            std::cout << "Empty record found, skipping..." << std::endl;
            continue;
        }

        Data record = Data();

        // convert line to string stream to be read from
        std::istringstream iss(line);

        // read from string stream into values

        record.setRecordNum(getIntFromISS(iss));
        record.setIdNum(getIntFromISS(iss));
        record.setName(getStrFromISS(iss));
        record.setEmail(getStrFromISS(iss));
        if (iss.peek() == 'A') {  // remove AU from credits and set credits to 0
            record.setUnits(0);   // what else should have been done here?
            iss.get();  // 'A'
            iss.get();  // 'U'
            iss.get();  // ','
        } else {  // otherwise just extract value
            record.setUnits(getDoubleFromISS(iss));
        }
        record.setProgram(getStrFromISS(iss));
        record.setLevel(getStrFromISS(iss));
        record.setAbsences(getIntFromISS(iss));
        std::stack<std::string> absences = std::stack<std::string>();
        while (iss.peek() != -1) {
            absences.push(getStrFromISS(iss));
        }
        record.setAbsenceDates(absences);

        if (record.validRecord()) {
            records.insertAtFront(record);
        }
    }

    infile.close();

    return true;
}
bool RecordManager::mmStoreMaster() {
    // try to open file to export to
    std::ofstream outfile(MASTER_LIST_FILE);

    if (!outfile.is_open()) {
        std::cerr << "Failed to open or create `" << MASTER_LIST_FILE << "` file! Could not store master list." << std::endl;
    }

    // write header line
    outfile << MASTER_LIST_HEADER_STRING << std::endl;
    
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
            absences.pop();
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

    // remove newline and carriage return from end of line
    // i'm not sure how else to do this. I've looked at
    // https://stackoverflow.com/questions/1488775/c-remove-new-line-from-multiline-string
    // but none of those worked. Probably because of the '\r'
    if (!tmp.empty()) {
        while (tmp.back() == '\n' || tmp.back() == '\r') {
            tmp.pop_back();
        }
    }

    return tmp;
}
