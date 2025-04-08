#include <iostream>

class Person {

public:
    Person();
    Person(std::string name, int age, std::string gender, double height);
    Person(const Person& copy);
    ~Person();

    // getters
    std::string getName() const;
    int getAge() const;
    std::string getGender() const;
    double getHeight() const;

    // setters
    void setName(std::string newName);
    void setAge(int newAge);
    void setGender(std::string newGender);
    void setHeight(double newHeight);

    // overloads
    Person& operator= (const Person& rhs);
    friend std::ostream& operator<< (std::ostream& lhs, const Person& rhs);
    friend std::istream& operator>> (std::istream& lhs, Person& rhs);

protected:
    std::string name;
    int age;
    std::string gender;
    double height;
};
