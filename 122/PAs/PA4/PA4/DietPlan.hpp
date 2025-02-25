#pragma once

#include <string>
#include <iostream>

class DietPlan {

private:
	int goal_calories;
	std::string plan_name;
	std::string date;

public:
	/* ----- Constructors ----- */
	DietPlan();
	//DietPlan(int goal, std::string plan, std::string date);

	/* ----- Rule of Three ----- */
	// Copy constructor
	//DietPlan(DietPlan& d);

	// Copy assignment constructor
	//DietPlan& operator=(DietPlan& rhs);

	// Destructor
	~DietPlan();

	/* ----- Getters ----- */
	int getCalories();
	std::string getPlanName();
	std::string getDate();

	/* ----- Setters ----- */
	void setCalories(int calories);
	void setPlanName(std::string plan_name);
	void setDate(std::string date);
};

// constructor
DietPlan::DietPlan() {
	goal_calories = 0;
	plan_name = "";
	date = "";
}

// destructor
DietPlan::~DietPlan() {}

/* ----- Getters ----- */
int DietPlan::getCalories() {
	return this->goal_calories;
}
std::string DietPlan::getPlanName() {
	return this->plan_name;
}
std::string DietPlan::getDate() {
	return this->date;
}

/* ----- Setters ----- */
void DietPlan::setCalories(int calories) {
	this->goal_calories = calories;
}
void DietPlan::setPlanName(std::string plan_name) {
	this->plan_name = plan_name;
}
void DietPlan::setDate(std::string date) {
	this->date = date;
}

// overloaded operators
// file insertion
std::fstream& operator<< (std::fstream& lhs, DietPlan& rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getCalories() << std::endl;
	lhs << rhs.getDate() << std::endl;

	return lhs;
}
// cout insertion
std::ostream& operator<< (std::ostream& lhs, DietPlan& rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getCalories() << std::endl;
	lhs << rhs.getDate() << std::endl;

	return lhs;
}
// cin extraction
std::istream& operator>> (std::istream& lhs, DietPlan& rhs) {
	// variables
	int goal;
	std::string plan, date, tmp;

	// extraction
	
	// consume blank line if that's what's next
	if ((char)lhs.peek() == '\n') std::getline(lhs, tmp);

	// set variables to default values if this is the end of the file
	if ((int)lhs.peek() < 0) {
		rhs.setCalories(0);
		rhs.setDate("");
		rhs.setPlanName("");
		return lhs;
	}
	
	std::getline(lhs, plan);
	lhs >> goal;
	std::getline(lhs, tmp); // newline after calorie goal
	std::getline(lhs, date);

	// setting
	rhs.setCalories(goal);
	rhs.setDate(date);
	rhs.setPlanName(plan);

	// debug
	std::cout << rhs.getPlanName() << ", " << rhs.getCalories() << ", " << rhs.getDate() << std::endl;

	return lhs;
}