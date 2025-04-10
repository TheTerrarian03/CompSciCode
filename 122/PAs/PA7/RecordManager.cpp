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
        << std::endl
        << "[1-7] > ";

    // read whole cin line and extract int option from it if possible
    std::getline(std::cin, input);
    std::istringstream iss(input);

    // return option chosen or 0 for fail
    if (iss >> option) return option;
    else return 0;
}
int RecordManager::reportMenu() {
    int option;
    std::string input;

    // prompt
    std::cout << "Let's generate you a report. Would you like to:" << std::endl
        << "  1. Generate a report for all students" << std::endl
        << "       (shows most recent absence for each student)" << std::endl
        << "  2. Generate a report based on minimum absences" << std::endl
        << "       (shows only students who have that many or more)" << std::endl
        << "  3. Cancel" << std::endl
        << std::endl
        << "[1-3] > ";
    
    std::getline(std::cin, input);
    std::istringstream iss(input);

    if (iss >> option) return option;
    else return 0;
}
int RecordManager::editMenu() {
    int option;
    std::string input;

    // prompt
    std::cout << "Let's edit the absences. Would you like to:" << std::endl
        << "  1. Edit a single student's absences" << std::endl
        << "  2. Clean up all duplicate absences for every student" << std::endl
        << "  3. Clear all absences for all students" << std::endl
        << "  4. Clear all absences for all students, for a particular day" << std::endl
        << "  5. Cancel" << std::endl
        << std::endl
        << "[1-5] > ";

    getline(std::cin, input);
    std::istringstream iss(input);

    if (iss >> option) return option;
    else return 0;
}
int RecordManager::minAbsenceMenu() {
    int minAbsences;

    // prompt for target # absences to look for
    std::cout << "How many minimum absences?" << std::endl << "[1 or more] > ";

    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);

    if (!(iss >> minAbsences)) {
        std::cout << "Please enter a number! Go try again." << std::endl;
        return 0;
    }

    if (minAbsences < 1) {
        std::cout << "Please enter a number > 0! Go try again." << std::endl;
        return 0;
    }

    return minAbsences;
}

// perform functions
bool RecordManager::performMainMenuOption(int option) {
    clearConsole();
    
    switch (option) {
        case 1: return mmImport();
        case 2: return mmLoadMaster();
        case 3: return mmStoreMaster();
        case 4: return mmMarkAbsences();
        case 5: return mmEditAbsences();
        case 6: return mmGenReports();
        default: {
            std::cout << "Not implemented!" << std::endl;
        }
    }

    return false;
}
bool RecordManager::performAllReport() {
    // open file for writing to, and check if open
    std::ofstream outfile(REPORT_ALL_FILE);

    if (!outfile.is_open()) {
        std::cerr << "There was an error opening `" << REPORT_ALL_FILE << "` for writing!" << std::endl;
        std::cout << "Canceling Report because file could not be created" << std::endl;
        return false;
    } else {
        outfile << "Report for all students generated on " << getDate() << "." << std::endl;
    }

    // stack of students - has and doesn't have absences
    std::stack<Data> naughty, nice;  // me when, me when im, whem, uh, santa !

    // tmp List
    List<Data> tmpList;

    // loop through students and sort by absences
    while (!records.isEmpty()) {
        Data student = records.pop();

        if (student.getAbsences() == 0) nice.push(student);
        else naughty.push(student);

        tmpList.insertAtFront(student);
    }

    // put students back into master list
    while (!tmpList.isEmpty()) {
        records.insertAtFront(tmpList.pop());
    }

    // print naughty (why did I name it like this)
    std::cout << std::endl << "-- Students with Absences: --" << std::endl;
    outfile << std::endl << "-- Students with Absences: --" << std::endl;
    for (int i=1; naughty.size() > 0; i++) {
        std::cout << "  " << i << ". "
            << "[" << naughty.top().getIdNum() << "] "
            << naughty.top().getName() << ": "
            << naughty.top().getAbsences() << " absences, most recent: "
            << naughty.top().getAbsenceDates().top() << std::endl;
        
        outfile << "  " << i << ". "
            << "[" << naughty.top().getIdNum() << "] "
            << naughty.top().getName() << ": "
            << naughty.top().getAbsences() << " absences, most recent: "
            << naughty.top().getAbsenceDates().top() << std::endl;
        
        naughty.pop();
    }

    // print nice
    std::cout << std::endl << "-- Students with NO Absences: --" << std::endl;
    outfile << std::endl << "-- Students with NO Absences: --" << std::endl;
    for (int i=1; nice.size() > 0; i++) {
        std::cout << "  " << i << ". "
            << "[" << nice.top().getIdNum() << "] "
            << nice.top().getName() << std::endl;
        
        outfile << "  " << i << ". "
            << "[" << nice.top().getIdNum() << "] "
            << nice.top().getName() << std::endl;
        
        nice.pop();
    }

    outfile.close();

    return true;
}
bool RecordManager::performSpecificReport(int minAbsences) {
    // open file for writing to, and check if open
    std::ofstream outfile(REPORT_SPECIFIC_FILE);

    if (!outfile.is_open()) {
        std::cerr << "There was an error opening `" << REPORT_SPECIFIC_FILE << "` for writing!" << std::endl;
        std::cout << "Canceling Report because file could not be created" << std::endl;
        return false;
    } else {
        outfile << "Report for all students generated on " << getDate() << "." << std::endl;
        outfile << "Looking for students with >= " << minAbsences << " absences." << std::endl;
    }

    // stack of students who meet the criteria
    std::stack<Data> absentEnough;

    // tmp list
    List<Data> tmpList;

    // loop through students and sort by absences
    while (!records.isEmpty()) {
        Data student = records.pop();

        if (student.getAbsences() >= minAbsences) absentEnough.push(student);
        tmpList.insertAtFront(student);
    }

    // put students back into master list
    while (!tmpList.isEmpty()) {
        records.insertAtFront(tmpList.pop());
    }

    // print absent people
    std::cout << std::endl << "Students with >= " << minAbsences << " absences:" << std::endl;
    outfile << std::endl << "Students with >= " << minAbsences << " absences:" << std::endl;
    for (int i=1; absentEnough.size() > 0; i++) {
        std::cout << "  " << i << ". "
            << "[" << absentEnough.top().getIdNum() << "] "
            << absentEnough.top().getName() << ": "
            << absentEnough.top().getAbsences() << " absences, most recent: "
            << absentEnough.top().getAbsenceDates().top() << std::endl;
        
        outfile << "  " << i << ". "
            << "[" << absentEnough.top().getIdNum() << "] "
            << absentEnough.top().getName() << ": "
            << absentEnough.top().getAbsences() << " absences, most recent: "
            << absentEnough.top().getAbsenceDates().top() << std::endl;
        
        absentEnough.pop();
    }

    outfile.close();

    return true;
}

// abstracted main menu functions
bool RecordManager::mmImport() {  // not motion magic, that's for frc
    // first, clear whatever's in the current list
    records.deleteList();

    // then, try to open file and exit if fail
    std::ifstream infile(CLASS_LIST_FILE);

    if (!infile.is_open()) {
        std::cerr << "Failed to open `" << CLASS_LIST_FILE << "` file! Could not read records." << std::endl;
        return false;
    }

    // temp list, will be flipped from what it should be
    List<Data> tmpList;

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
            tmpList.insertAtFront(record);
        }
    }

    while (!tmpList.isEmpty()) {
        records.insertAtFront(tmpList.pop());
    }

    infile.close();

    std::cout << "-- Successfully Imported from the class list!" << std::endl << std::endl;

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

    // flipped temp list
    List<Data> tmpList;

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
        std::stack<std::string> flipped;
        while (absences.size() > 0) {
            flipped.push(absences.top());
            absences.pop();
        }
        record.setAbsenceDates(flipped);

        if (record.validRecord()) {
            tmpList.insertAtFront(record);
        }
    }
    
    // insert from temp list to records in correct order
    while (!tmpList.isEmpty()) {
        records.insertAtFront(tmpList.pop());
    }
    
    infile.close();

    std::cout << "-- Successfully Loaded from the master list!" << std::endl << std::endl;

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
    
    // copy of records to pop from
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

    std::cout << "-- Successfully Stored the master list!" << std::endl << std::endl;

    return true;
}
bool RecordManager::mmMarkAbsences() {
    std::string date = getDate();

    std::cout << "current date: " << date << std::endl;
    
    // make new list to push updated records onto
    List<Data> newRecords;

    // loop through records
    while (!records.isEmpty()) {
        Data student = records.pop();

        std::cout << "Was " << student.getName() << " absent today? (y/N): ";

        std::string input;
        getline(std::cin, input);

        if (input[0] == 'y') {
            student.addAbsence(date);
        }

        newRecords.insertAtFront(student);
    }

    while (!newRecords.isEmpty()) {
        records.insertAtFront(newRecords.pop());
    }

    return true;
}
bool RecordManager::mmEditAbsences() {
    int option = editMenu();

    if (option == 5) {
        std::cout << "Canceling Edit..." << std::endl;
        return true;
    }

    if (option < 1 || option > 4) {
        std::cout << "Please enter a number 1-4! Go try again." << std::endl;
        return false;
    }

    switch (option) {
        case 1: return editStudent();
        case 2: return editDuplicates();
        case 3: return editClear();
        case 4: return editClearDay();
        default: {
            std::cerr << "There was somehow an error, please try again." << std::endl;
            // returns false below
        }
    }

    return false;
}
bool RecordManager::mmGenReports() {
    int type = reportMenu();

    if (type == 3) {
        if (type == 3) std::cout << "Canceling Report Generation..." << std::endl;
        return true;
    } else if (type < 1 || type > 3) {
        std::cout << "Invalid number entered!" << std::endl;
        return true;
    }

    // perform report on all students
    if (type == 1) return performAllReport();

    // otherwise, get what min absence count to look for
    int minAbsences = minAbsenceMenu();

    if (minAbsences > 0) return performSpecificReport(minAbsences);

    // minAbsences was too low, don't generate a report
    return false;
}

// abstracted edit menu functions
bool RecordManager::editStudent() {
    // temp list to store students
    List<Data> tmpList;

    std::cout << "Here are the students you have, and their ID numbers:" << std::endl;
    while (!records.isEmpty()) {
        Data student = records.pop();

        std::cout << "  - " << " [" << student.getIdNum() << "] "
            << student.getName() << std::endl;
    
        tmpList.insertAtFront(student);
    }

    std::cout << "Please enter a student name (exact match) or ID number to edit:" << std::endl << "> ";
    
    int idNum;
    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);

    Data toEdit;
    bool found = false;

    // based on ID num:
    if (iss >> idNum) {
        while (!tmpList.isEmpty()) {
            Data student = tmpList.pop();
            if (student.getIdNum() == idNum) {
                // set to edit to student and stop loop
                toEdit = student;
                found = true;
                break;
            } else {
                // put student back onto main list
                records.insertAtFront(student);
            }
        }

        if (!found) std::cout << "Sorry, couldn't find student with ID: " << idNum << std::endl;
    } else {
        while (!tmpList.isEmpty()) {
            Data student = tmpList.pop();
            if (student.getName() == input) {
                // set to edit to student and stop loop
                toEdit = student;
                found = true;
                break;
            } else {
                // put student back onto main list
                records.insertAtFront(student);
            }
        }

        if (!found) std::cout << "Sorry, couldn't find student with name: " << input << std::endl;
    }

    if (!found) return false;

    std::cout << "Here are the days they're absent:" << std::endl;

    std::stack<std::string> absences = toEdit.getAbsenceDates();

    while (absences.size() > 0) {
        std::cout << "  - " << absences.top() << std::endl;
        absences.pop();
    }

    // prompt for day
    std::string dateToDel;

    std::cout << "Which date would you like to remove? (Exact match) (Will remove duplicate entries of date entered)"
        << std::endl << "> ";
    
    getline(std::cin, dateToDel);

    absences = toEdit.getAbsenceDates();
    std::stack<std::string> newAbsences;

    while (absences.size() > 0) {
        if (absences.top() != dateToDel) newAbsences.push(absences.top());
        absences.pop();
    }

    toEdit.setAbsenceDates(newAbsences);

    // stich toEdit and rest of students back into master list
    records.insertAtFront(toEdit);

    while (!tmpList.isEmpty()) {
        records.insertAtFront(tmpList.pop());
    }

    return true;
}
bool RecordManager::editDuplicates() {
    int duplicatesRemoved = 0;

    List<Data> tmpList;

    while (!records.isEmpty()) {
        std::vector<std::string> dates;

        Data student = records.pop();

        std::stack<std::string> currentDates = student.getAbsenceDates();
        std::stack<std::string> newDates;

        while (currentDates.size() > 0) {
            bool alreadyAdded = false;
            for (std::string date : dates) {
                if (currentDates.top() == date) alreadyAdded = true;
            }
            if (!alreadyAdded) {
                newDates.push(currentDates.top());
                dates.push_back(currentDates.top());
            } else {
                duplicatesRemoved++;
            }
            currentDates.pop();
        }

        std::stack<std::string> flippedDates;

        while (newDates.size() > 0) {
            flippedDates.push(newDates.top());
            newDates.pop();
        }

        student.setAbsenceDates(flippedDates);

        tmpList.insertAtFront(student);
    }

    while (!tmpList.isEmpty()) records.insertAtFront(tmpList.pop());

    std::cout << "Removed " << duplicatesRemoved << " duplicate" << (duplicatesRemoved == 1 ? "" : "s") << "!" << std::endl;

    return true;
}
bool RecordManager::editClear() {
    int absencesRemoved = 0;

    List<Data> tmpList;

    while (!records.isEmpty()) {
        Data student = records.pop();

        std::stack<std::string> absences = student.getAbsenceDates();

        while (absences.size() > 0) {
            absencesRemoved++;
            absences.pop();
        }

        student.setAbsenceDates(absences);  // set to empty stack now

        tmpList.insertAtFront(student);
    }

    while (!tmpList.isEmpty()) {
        records.insertAtFront(tmpList.pop());
    }

    std::cout << "Removed " << absencesRemoved << " absences" << (absencesRemoved == 1 ? "" : "s") << "!" << std::endl;

    return true;
}
bool RecordManager::editClearDay() {
    List<Data> tmpList;
    std::vector<std::string> dates;

    // very non-optimized, slow, algorithm.
    while(!records.isEmpty()) {
        Data student = records.pop();

        std::stack<std::string> absences = student.getAbsenceDates();

        while (absences.size() > 0) {
            bool found = false;
            for (std::string date : dates) {
                if (date == absences.top()) {
                    found = true;
                }
            }
            if (!found) dates.push_back(absences.top());
            absences.pop();
        }

        tmpList.insertAtFront(student);
    }

    std::cout << "Here are the days students have been absent:" << std::endl;
    for (std::string date : dates) {
        std::cout << "  - " << date << std::endl;
    }

    std::cout << "Which date would you like to remove? (Exact Match)" << std::endl << "> ";

    std::string dateToDel;
    getline(std::cin, dateToDel);

    int datesRemoved = 0;

    while (!tmpList.isEmpty()) {
        Data student = tmpList.pop();

        std::stack<std::string> currentDates = student.getAbsenceDates();
        std::stack<std::string> newDates;

        while (currentDates.size() > 0) {
            if (currentDates.top() != dateToDel) {
                newDates.push(currentDates.top());
            } else {
                datesRemoved++;
            }
            currentDates.pop();
        }

        std::stack<std::string> flippedDates;

        while (newDates.size() > 0) {
            flippedDates.push(newDates.top());
            newDates.pop();
        }

        student.setAbsenceDates(flippedDates);

        records.insertAtFront(student);
    }

    std::cout << "Removed " << datesRemoved << " absences" << (datesRemoved == 1 ? "" : "s") << "!" << std::endl;

    return true;
}

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
