#pragma once

#include <iostream>
#include <stack>

class Data {

public:
    // constructors & destructor
    Data(int _recordNum=-1,
         int _idNum=-1,
         std::string _name = "",
         std::string _email = "",
         double _units = 0,
         std::string _program = "",
         std::string _level = "",
         int _absences = 0,
         std::stack<std::string> _absenceDates = std::stack<std::string>());
    ~Data();
    Data(const Data& copy);

    // getters
    int getRecordNum() const;
    int getIdNum() const;
    std::string getName() const;
    std::string getEmail() const;
    double getUnits() const;
    std::string getProgram() const;
    std::string getLevel() const;
    int getAbsences() const;
    std::stack<std::string>& getAbsenceDates();

    bool validRecord() const;

    // setters
    void setRecordNum(int _recordNum);
    void setIdNum(int _idNum);
    void setName(const std::string& _name);
    void setEmail(const std::string& _email);
    void setUnits(double _units);
    void setProgram(const std::string& _program);
    void setLevel(const std::string& _level);
    void setAbsences(int _absences);
    void setAbsenceDates(const std::stack<std::string>& _tmpAbsenceStack);

    // friend functions for operator overloads
    friend std::ostream& operator<<(std::ostream& lhs, const Data& rhs);

private:
    // record fields    
    int recordNum;
    int idNum;
    std::string name;
    std::string email;
    double units;
    std::string program;
    std::string level;

    // absences
    int absences;
    std::stack<std::string> absenceDates;
};