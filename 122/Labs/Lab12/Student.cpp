#include "Student.hpp"

Student::Student() : courses({}), numCoursesTaken(0), totalCredits(0) {}
Student::Student(std::string name, int age, std::string gender, double height) 
    : courses({}), numCoursesTaken(0), totalCredits(0), Person(name, age, gender, height) {}
Student::~Student() {}

// setters
void Student::addCourse(Course toAdd) {
    courses[numCoursesTaken++] = toAdd;
}
void Student::removeCourse(Course toRemove) {
    numCoursesTaken--;
    // optionally, actually delete data in array
}

int Student::getNumCoursesTaken() const {
    return numCoursesTaken;
}
double Student::getCredits() const {
    double credits = 0;

    for (int i=0; i < numCoursesTaken; i++) {
        credits += courses[i].credits;
    }

    return credits;
}
double Student::getGPA() const {
    if (numCoursesTaken == 0) return 0;
    
    double gradeTotal = 0;

    for (int i=0; i < numCoursesTaken; i++) {
        gradeTotal += courses[i].currentGrade;
    }

    return gradeTotal/(double)numCoursesTaken;
}

std::ostream& operator<< (std::ostream& lhs, const Student& rhs) {
    lhs << rhs.name << " "
        << rhs.age << " "
        << rhs.gender << " "
        << rhs.height << " "
        << rhs.getNumCoursesTaken() << " "
        << rhs.getCredits() << " "
        << rhs.getGPA() << std::endl;

    return lhs;
}
// std::istream& operator>> (std::istream& lhs, Student& rhs) {
//     lhs >> rhs.name;
//     lhs >> rhs.age;
//     lhs >> rhs.gender;
//     lhs >> rhs.height;

//     return lhs;
// }