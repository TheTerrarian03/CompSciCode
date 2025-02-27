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
	DietPlan(DietPlan& d);

	// Copy assignment constructor
	DietPlan& operator=(DietPlan& rhs);

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

	/* ----- Edit ----- */
	void editPlan();
};

/*
 * Function: DietPlan
 * --------------------
 *   Main constructor for a new DietPlan
 *
*/
DietPlan::DietPlan() {
	goal_calories = 0;
	plan_name = "";
	date = "";
}

// Copy constructor

/*
 * Function: DietPlan
 * --------------------
 *   Copy Constructor for a new DietPlan
 *
 *   Parameters:
 *   - d: the existing plan to copy from
 *
*/
DietPlan::DietPlan(DietPlan& d) {
	this->goal_calories = d.getCalories();
	this->plan_name = d.getPlanName();
	this->date = d.getDate();
}

// Copy assignment constructor

/*
 * Function: DietPlan
 * --------------------
 *   Copy Assignment constructor for an DietPlan
 *
 *   Parameters:
 *   - rhs: the plan to copy from
 *
*/
DietPlan& DietPlan::operator=(DietPlan& rhs) {
	this->goal_calories = rhs.getCalories();
	this->plan_name = rhs.getPlanName();
	this->date = rhs.getDate();

	return *this;
}

// destructor

/*
 * Function: ~DietPlan
 * --------------------
 *   Deconstructor. Does nothing because nothing needs to be done (no dynamic memory to take care of)
 *
*/
DietPlan::~DietPlan() {}

/* ----- Getters ----- */

/*
 * Function: getCalories
 * --------------------
 *   Get the goal calories
 *
 *   Returns:
 *   - int
 *
*/
int DietPlan::getCalories() {
	return this->goal_calories;
}

/*
 * Function: getPlanName
 * --------------------
 *   Get the goal plan name
 *
 *   Returns:
 *   - std::string
 *
*/
std::string DietPlan::getPlanName() {
	return this->plan_name;
}

/*
 * Function: getDate
 * --------------------
 *   Get the goal date
 *
 *   Returns:
 *   - std::string
 *
*/
std::string DietPlan::getDate() {
	return this->date;
}

/* ----- Setters ----- */

/*
 * Function: setCalories
 * --------------------
 *   Set a new calories goal
 *
 *   Parameters:
 *   - steps: new calories goal
 *
*/
void DietPlan::setCalories(int calories) {
	this->goal_calories = calories;
}

/*
 * Function: setPlanName
 * --------------------
 *   Set a new plan name
 *
 *   Parameters:
 *   - steps: new plan name
 *
*/
void DietPlan::setPlanName(std::string plan_name) {
	this->plan_name = plan_name;
}

/*
 * Function: setDate
 * --------------------
 *   Set a new date
 *
 *   Parameters:
 *   - steps: new date
 *
*/
void DietPlan::setDate(std::string date) {
	this->date = date;
}

/* ----- Overloaded Operators ----- */

/*
 * Function: operator<<
 * --------------------
 *   Write the plan to the given file stream
 *
 *   Parameters:
 *   - lhs: file stream to write to
 *   - rhs: plan to write
 *
 *   Returns:
 *   - edited file stream, lhs
*/
std::fstream& operator<< (std::fstream& lhs, DietPlan& rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getCalories() << std::endl;
	lhs << rhs.getDate() << std::endl;

	return lhs;
}

/*
 * Function: operator<<
 * --------------------
 *   Write the plan to the given ostream
 *
 *   Parameters:
 *   - lhs: ostream to write to
 *   - rhs: plan to write
 *
 *   Returns:
 *   - edited ostream, lhs
*/
std::ostream& operator<< (std::ostream& lhs, DietPlan& rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getCalories() << std::endl;
	lhs << rhs.getDate() << std::endl;

	return lhs;
}

/*
 * Function: operator>>
 * --------------------
 *   Read from an istream to overwrite this plan's attributes
 *
 *   Parameters:
 *   - lhs: istream to read from
 *   - rhs: plan to overwrite
 *
 *   Returns:
 *   - edited istream, lhs
*/
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
	//std::cout << rhs.getPlanName() << ", " << rhs.getCalories() << ", " << rhs.getDate() << std::endl;

	return lhs;
}

/* ----- Edit ----- */

/*
 * Function: editPlan
 * --------------------
 *   Get input from user and overwrite existing data
 *
*/
void DietPlan::editPlan() {
	std::string tmp_cals = "";

	std::cout << "Enter new plan name (current: \"" << this->plan_name << "\"): ";

	std::getline(std::cin, this->plan_name);  // same stuff here
	std::getline(std::cin, this->plan_name);

	std::cout << "Enter a new steps goal (current: " << this->goal_calories << "): ";

	std::getline(std::cin, tmp_cals);

	this->goal_calories = std::stoi(tmp_cals);

	std::cout << "Enter a new date (current: " << this->date << "): ";

	std::getline(std::cin, date);
}
