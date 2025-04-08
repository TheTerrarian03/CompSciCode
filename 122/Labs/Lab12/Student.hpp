#include "Person.hpp"

class Student : public Person {

public:
    struct Course {
        std::string courseName;
        double credits;
        double currentGrade;
    };

    Student();
    Student(std::string name, int age, std::string gender, double height);
    ~Student();

    // setters
    void addCourse(Course toAdd);
    void removeCourse(Course toRemove);
    
    int getNumCoursesTaken() const;
    double getCredits() const;
    double getGPA() const;

    // overloads
    friend std::ostream& operator<< (std::ostream& lhs, const Student& rhs);
    // friend std::istream& operator>> (std::istream& lhs, Student& rhs);

private:
    Course courses[10];
    int numCoursesTaken;
    double totalCredits;

};