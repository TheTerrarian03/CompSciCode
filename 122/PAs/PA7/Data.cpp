#include "Data.hpp"

// constructors & destructor
Data::Data(int _recordNum,
    int _idNum,
    std::string _name,
    std::string _email,
    double _units,
    std::string _program,
    std::string _level,
    int _absences,
    std::stack<std::string> _absenceDates) {

    recordNum = _recordNum;
    idNum = _idNum;
    name = _name;
    email = _email;
    units = _units;
    program = _program;
    level = _level;
    absences = _absences;

    // absence stack here
}
Data::~Data() {}
Data::Data(const Data& copy) {
    recordNum = copy.recordNum;
    idNum = copy.idNum;
    name = copy.name;
    email = copy.email;
    units = copy.units;
    program = copy.program;
    level = copy.level;
    absences = copy.absences;
    absenceDates = copy.absenceDates;  // turn out this one missing line will cause your program to not work properly! no more dates :shrug:
}

// getters
int Data::getRecordNum() const { return recordNum; }
int Data::getIdNum() const { return idNum; }
std::string Data::getName() const { return name; }
std::string Data::getEmail() const { return email; }
double Data::getUnits() const { return units; }
std::string Data::getProgram() const { return program; }
std::string Data::getLevel() const { return level; }
int Data::getAbsences() const { return absences; }
std::stack<std::string>& Data::getAbsenceDates() { return absenceDates; }

bool Data::validRecord() const {
    if (recordNum != -1 &&
        idNum != -1 &&
        name != "" &&
        email != "" &&
        program != "" &&
        level != "") return true;
    
    return false;
}

// setters
void Data::setRecordNum(int _recordNum) { recordNum = _recordNum; }
void Data::setIdNum(int _idNum) { idNum = _idNum; }
void Data::setName(const std::string& _name) { name = _name; }
void Data::setEmail(const std::string& _email) { email = _email; }
void Data::setUnits(double _units) { units = _units; }
void Data::setProgram(const std::string& _program) { program = _program; }
void Data::setLevel(const std::string& _level) { level = _level; }
void Data::setAbsences(int _absences) { absences = _absences; }
void Data::setAbsenceDates(const std::stack<std::string>& _tmpAbsenceStack) { 
    absenceDates = _tmpAbsenceStack;  // deep copy of tmp stack to absenceDates via std::stack's operator=
}

// operator overloads
std::ostream& operator<<(std::ostream& lhs, const Data& rhs) {
    lhs << "Record Number: " << rhs.recordNum << "\n"
       << "ID Number: " << rhs.idNum << "\n"
       << "Name: " << rhs.name << "\n"
       << "Email: " << rhs.email << "\n"
       << "Units: " << rhs.units << "\n"
       << "Program: " << rhs.program << "\n"
       << "Level: " << rhs.level << "\n"
       << "Absences: " << rhs.absences << "\n"
       << "Absence Dates: ";

    // print absence dates stack
    if (rhs.absenceDates.empty()) {
        lhs << "None";
    } else {
        std::stack<std::string> temp = rhs.absenceDates; // Copy to avoid modifying the original
        while (!temp.empty()) {
            lhs << temp.top() << " ";
            temp.pop();
        }
    }
    lhs << std::endl << std::endl;
    return lhs;
}