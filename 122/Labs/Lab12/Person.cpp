#include "Person.hpp"

Person::Person() : name(""), age(0), gender(""), height(0.0) {}
Person::Person(std::string name, int age, std::string gender, double height) :
    name(name), age(age), gender(gender), height(height) {}
Person::Person(const Person& copy) {
    name = copy.name;
    age = copy.age;
    gender = copy.gender;
    height = copy.height;
}
Person::~Person() {}

// getters
std::string Person::getName() const { return name; }
int Person::getAge() const { return age; }
std::string Person::getGender() const { return gender; }
double Person::getHeight() const { return height; }

// setters
void Person::setName(std::string newName) { name = newName; }
void Person::setAge(int newAge) { age = newAge; }
void Person::setGender(std::string newGender) { gender = newGender; }
void Person::setHeight(double newHeight) { height = newHeight; }

// overloads
Person& Person::operator= (const Person& rhs) {
    name = rhs.age;
    age = rhs.age;
    gender = rhs.gender;
    height = rhs.height;
    return *this;
}
std::ostream& operator<< (std::ostream& lhs, const Person& rhs) {
    lhs << rhs.name << " "
        << rhs.age << " "
        << rhs.gender << " "
        << rhs.height << std::endl;
    
    return lhs;
}
std::istream& operator>> (std::istream& lhs, Person& rhs) {
    lhs >> rhs.name;
    lhs >> rhs.age;
    lhs >> rhs.gender;
    lhs >> rhs.height;

    return lhs;
}