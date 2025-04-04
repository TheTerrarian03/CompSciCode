#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Employee is a base class
class Employee
{
	// We will not use qualifiers (i.e. like const) in all possible places
	// in this example to simplify a bit
public:
	Employee(const string& newName = "", const double& newPayRate = 8.55, const double& newHours = 0.0);
	virtual ~Employee();  // allows derived classes to call this desturctor then clean up derived object

	string getName();
	double getPayRate();
	double getHours();

	void setName(const string& newName);
	void setPayRate(const double& newPayRate);
	void setHours(const double& newHours);

	virtual double calculatePay();  // to override a function

protected:  // attributes are now acquired by objects inheriting from this class
	string mName;
	double mPayRate;
	double mHours;
};