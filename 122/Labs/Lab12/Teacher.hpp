#include "Person.hpp"

class Teacher : public Person {
    struct Course {
        std::string courseName;
        double credits;
        double averageStudentGrade;
    };

    Teacher();
    Teacher(std::string name, int age, std::string gender, double height);
    ~Teacher();

    // setters
    void addCourse(Course toAdd);
    void removeCourse(Course toRemove);
    
    int getNumCoursesTaken() const;
    double getCredits() const;
    double getGPA() const;

    // overloads
    friend std::ostream& operator<< (std::ostream& lhs, const Teacher& rhs);
    // friend std::istream& operator>> (std::istream& lhs, Teacher& rhs);

private:
    Course courses[10];
    int numCoursesTaken;
    double totalCredits;
};
