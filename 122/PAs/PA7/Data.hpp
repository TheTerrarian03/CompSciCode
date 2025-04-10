/*
- Name: Logan Meyers
- TA: Martin Hundrup
- Date Finished: 04-09-2025
- Program: Student Absence Manager

- File: Data.hpp
- What: Class declaration for my Data class, holding student record data
*/

#pragma once

#include <iostream>
#include <stack>

class Data {

public:
    /* ----- Constructors & Destructors ----- */
    // constructor - all data points with default values
    Data(int _recordNum=-1,
         int _idNum=-1,
         std::string _name = "",
         std::string _email = "",
         double _units = 0,
         std::string _program = "",
         std::string _level = "",
         int _absences = 0,
         std::stack<std::string> _absenceDates = std::stack<std::string>());
    // copy constructor
    Data(const Data& copy);
    // destructor
    ~Data();

    /* ----- Getters ----- */
    // Get the record number
    int getRecordNum() const;
    // Get the id num
    int getIdNum() const;
    // Get the name
    std::string getName() const;
    // Get the email
    std::string getEmail() const;
    // Get the units
    double getUnits() const;
    // Get the program
    std::string getProgram() const;
    // Get the level
    std::string getLevel() const;
    // Get the number of absences
    int getAbsences() const;
    // Get a reference to the stack of absences
    std::stack<std::string>& getAbsenceDates();
    // whether the record is valid or not (enough valid data members)
    bool validRecord() const;

    /* ----- Setters ----- */
    // Set the record number
    void setRecordNum(int _recordNum);
    // Set the id num
    void setIdNum(int _idNum);
    // Set the name
    void setName(const std::string& _name);
    // Set the email
    void setEmail(const std::string& _email);
    // Set the units
    void setUnits(double _units);
    // Set the program
    void setProgram(const std::string& _program);
    // Set the level
    void setLevel(const std::string& _level);
    // Set the number of absences
    void setAbsences(int _absences);
    // Deep copy a stack of absences. also sets proper num absences
    void setAbsenceDates(const std::stack<std::string>& _tmpAbsenceStack);
    // Add another absence date. also increments num absences
    void addAbsence(const std::string& date);

    /* ----- Overloaded Operator ----- */
    friend std::ostream& operator<<(std::ostream& lhs, const Data& rhs);

private:
    /* ----- Record Fields ----- */
    int recordNum;
    int idNum;
    std::string name;
    std::string email;
    double units;
    std::string program;
    std::string level;

    /* ----- Absence Members ----- */
    int absences;
    std::stack<std::string> absenceDates;
};