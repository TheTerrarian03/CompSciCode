#pragma once

#include <string>

class ExercisePlan {

private:
	int goal_steps;
	std::string plan_name;
	std::string date;

public:
	/* ----- Constructors ----- */
	ExercisePlan();
	//ExercisePlan(int goal, std::string plan, std::string date);

	/* ----- Rule of Three ----- */
	// Copy constructor
	ExercisePlan(ExercisePlan& d);

	// Copy assignment constructor
	ExercisePlan& operator=(ExercisePlan& rhs);

	// Destructor
	~ExercisePlan();

	/* ----- Getters ----- */
	int getSteps();
	std::string getPlanName();
	std::string getDate();

	/* ----- Setters ----- */
	void setSteps(int steps);
	void setPlanName(std::string plan_name);
	void setDate(std::string date);

	/* ----- Edit ----- */
	void editPlan();
};

/*
 * Function: ExercisePlan
 * --------------------
 *   Main constructor for a new ExercisePlan
 *
*/
ExercisePlan::ExercisePlan() {
	goal_steps = 0;
	plan_name = "";
	date = "";
}

/*
 * Function: ExercisePlan
 * --------------------
 *   Copy Constructor for a new ExercisePlan
 *
 *   Parameters:
 *   - d: the existing plan to copy from
 * 
*/
ExercisePlan::ExercisePlan(ExercisePlan& d) {
	this->goal_steps = d.getSteps();
	this->plan_name = d.getPlanName();
	this->date = d.getDate();
}

/*
 * Function: ExercisePlan
 * --------------------
 *   Copy Assignment constructor for an ExercisePlan
 *
 *   Parameters:
 *   - rhs: the plan to copy from
 *
*/
ExercisePlan& ExercisePlan::operator=(ExercisePlan& rhs) {
	this->goal_steps = rhs.getSteps();
	this->plan_name = rhs.getPlanName();
	this->date = rhs.getDate();

	return *this;
}

/*
 * Function: ~ExercisePlan
 * --------------------
 *   Deconstructor. Does nothing because nothing needs to be done (no dynamic memory to take care of)
 * 
*/
ExercisePlan::~ExercisePlan() {}

/* ----- Getters ----- */

/*
 * Function: getSteps
 * --------------------
 *   Get the goal steps
 *
 *   Returns:
 *   - int
 * 
*/
int ExercisePlan::getSteps() {
	return this->goal_steps;
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
std::string ExercisePlan::getPlanName() {
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
std::string ExercisePlan::getDate() {
	return this->date;
}

/* ----- Setters ----- */

/*
 * Function: setSteps
 * --------------------
 *   Set a new step goal
 *
 *   Parameters:
 *   - steps: new step goal
 *
*/
void ExercisePlan::setSteps(int steps) {
	this->goal_steps = steps;
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
void ExercisePlan::setPlanName(std::string plan_name) {
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
void ExercisePlan::setDate(std::string date) {
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
 * 
*/
std::fstream& operator<< (std::fstream& lhs, ExercisePlan& rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getSteps() << std::endl;
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
 * 
*/
std::ostream& operator<< (std::ostream& lhs, ExercisePlan& rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getSteps() << std::endl;
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
 * 
*/
std::istream& operator>> (std::istream& lhs, ExercisePlan& rhs) {
	// variables
	int goal;
	std::string plan, date, tmp;

	// consume blank line if that's what's next
	if ((char)lhs.peek() == '\n') std::getline(lhs, tmp);

	// set variables to default values if this is the end of the file
	if ((int)lhs.peek() < 0) {
		rhs.setSteps(0);
		rhs.setDate("");
		rhs.setPlanName("");
		return lhs;
	}

	std::getline(lhs, plan);
	lhs >> goal;
	std::getline(lhs, tmp); // newline after steps goal
	std::getline(lhs, date);

	// setting
	rhs.setSteps(goal);
	rhs.setDate(date);
	rhs.setPlanName(plan);

	// debug
	//std::cout << rhs.getPlanName() << ", " << rhs.getSteps() << ", " << rhs.getDate() << std::endl;

	return lhs;
}

/* ----- Edit ----- */

/*
 * Function: editPlan
 * --------------------
 *   Get input from user and overwrite existing data
 *
*/
void ExercisePlan::editPlan() {
	std::string tmp_steps = "";

	std::cout << "Enter new plan name (current: \"" << this->plan_name << "\"): ";

	std::getline(std::cin, this->plan_name);  // same stuff here
	std::getline(std::cin, this->plan_name);

	std::cout << "Enter a new steps goal (current: " << this->goal_steps << "): ";

	std::getline(std::cin, tmp_steps);

	this->goal_steps = std::stoi(tmp_steps);

	std::cout << "Enter a new date (current: " << this->date << "): ";

	std::getline(std::cin, date);
}
