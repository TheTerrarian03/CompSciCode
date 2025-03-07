#include <iostream>

class Data {

public:
    // constructors and destructor
    Data() : customerNumber(0), serviceTime(0), totalTime(0) {}  // constructor
    Data(int customerNumber, int serviceTime, int totalTime) : customerNumber(customerNumber), serviceTime(serviceTime), totalTime(totalTime) {}
    Data(Data &rhs) {
        this->customerNumber = rhs.getCustomerNumber();
        this->serviceTime = rhs.getServiceTime();
        this->totalTime = rhs.getTotalTime();
    }
    ~Data() {}

    // setters
    void setCustomerNumber(int newNumber) { this->customerNumber = newNumber; }
    void setServiceTime(int newServiceTime) { this->serviceTime = newServiceTime; }
    void setTotalTime(int newTotalTime) { this->totalTime = newTotalTime; }

    // getters
    int getCustomerNumber() { return this->customerNumber; }
    int getServiceTime() { return this->serviceTime; }
    int getTotalTime() { return this->totalTime; }

private:
    int customerNumber;
    int serviceTime;
    int totalTime;
};  // allocated on the heap

// overload stream insert
std::ostream& operator<< (std::ostream& lhs, Data &rhs) {
    lhs << rhs.getCustomerNumber() << std::endl;
    lhs << rhs.getServiceTime() << std::endl;
    lhs << rhs.getTotalTime() << std::endl;
    return lhs;
}