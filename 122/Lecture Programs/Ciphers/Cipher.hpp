#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// abstract class, since >= 1 virtual functions are pure
// abstract class is not instatiatable.
// you must create a class that inherits from this
class Cipher {

public:
    virtual string encode(string &msg) = 0;  // pure virtual function
    virtual string decode(string &msg) = 0;  // pure virtual function

private:

};