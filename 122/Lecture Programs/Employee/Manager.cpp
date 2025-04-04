#include "Manager.hpp"

double Manager::calculatePay() {
    // pay rate. may be salaried
    double pay = this->mPayRate;

    if (!this->mIsSalaried) {
        // is hourly instead, replace pay
        pay = Employee::calculatePay();
    }

    return pay;
}