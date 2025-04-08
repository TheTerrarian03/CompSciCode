#include "Person.hpp"

class TestPerson : private Person {
    
public:
    TestPerson();

    bool testGetName();
    bool testGetAge();
    bool testGetGender();
    bool testGetHeight();

    bool testSetName();
    bool testSetAge();
    bool testSetGender();
    bool testSetHeight();

    // bool testStringInsertion();
    // bool testStringExtraction();

    bool testAll();

private:
    
};