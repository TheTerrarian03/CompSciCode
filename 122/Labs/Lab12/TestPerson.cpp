#include "TestPerson.hpp"

TestPerson::TestPerson() {}

// modifying Person to have protected members allows for test cases to more directly access them
// rather than having to rely on setters & getters

bool TestPerson::testGetName() {
    // setName("Bob");
    this->name = "Bob";
    if (getName() == "Bob") return true;
    return false;
}
bool TestPerson::testGetAge() {
    // setAge(24);
    age = 24;
    if (getAge() == 24) return true;
    return false;
}
bool TestPerson::testGetGender() {
    // setGender("horse");
    gender = "horse";
    if (getGender() == "horse") return true;
    return false;
}
bool TestPerson::testGetHeight() {
    // setHeight(123.7);
    height = 123.7;
    if (getHeight() == 123.7) return true;
    return false;
}

bool TestPerson::testSetName() {
    setName("Bob");
    // if (getName() == "Bob") return true;
    if (name == "Bob") return true;
    return false;
}
bool TestPerson::testSetAge() {
    setAge(24);
    // if (getAge() == 24) return true;
    if (age == 24) return true;
    return false;
}
bool TestPerson::testSetGender() {
    setGender("horse");
    // if (getGender() == "horse") return true;
    if (gender == "horse") return true;
    return false;
}
bool TestPerson::testSetHeight() {
    setHeight(123.7);
    // if (getHeight() == 123.7) return true;
    if (height == 123.7) return true;
    return false;
}

// bool TestPerson::testStringInsertion() {
//     std::ostringstream oss();

//     oss << *this;
// }
// bool TestPerson::testStringExtraction();

bool TestPerson::testAll() {
    return testGetName() &&
        testGetAge() &&
        testGetGender() &&
        testGetHeight() &&
        testSetName() &&
        testSetAge() &&
        testSetGender() &&
        testSetHeight();
        // testStringInsertion() &&
        // testStringExtraction();
}