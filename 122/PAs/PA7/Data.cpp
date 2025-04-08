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
    recordNum = copy.getRecordNum();
    idNum = copy.getIdNum();
    name = copy.getName();
    email = copy.getEmail();
    units = copy.getUnits();
    program = copy.getProgram();
    level = copy.getLevel();
    absences = copy.getAbsences();
    
    // absence stack here
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
std::stack<std::string> Data::getAbsenceDates() const { return absenceDates; }

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
void Data::setAbsenceDates(const std::stack<std::string>& _absenceDates) { 
    absenceDates = _absenceDates; 
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