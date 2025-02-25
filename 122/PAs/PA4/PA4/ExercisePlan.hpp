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
	//ExercisePlan(ExercisePlan& d);

	// Copy assignment constructor
	//ExercisePlan& operator=(ExercisePlan& rhs);

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
};

// constructor
ExercisePlan::ExercisePlan() {
	goal_steps = 0;
	plan_name = "";
	date = "";
}

// deconstructur (marting)
ExercisePlan::~ExercisePlan() {}

/* ----- Getters ----- */
int ExercisePlan::getSteps() {
	return this->goal_steps;
}
std::string ExercisePlan::getPlanName() {
	return this->plan_name;
}
std::string ExercisePlan::getDate() {
	return this->date;
}

/* ----- Setters ----- */
void ExercisePlan::setSteps(int steps) {
	this->goal_steps = steps;
}
void ExercisePlan::setPlanName(std::string plan_name) {
	this->plan_name = plan_name;
}
void ExercisePlan::setDate(std::string date) {
	this->date = date;
}

// overloaded operators
// file insertion
std::fstream& operator<< (std::fstream& lhs, ExercisePlan& rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getSteps() << std::endl;
	lhs << rhs.getDate() << std::endl;

	return lhs;
}
// cout insertion
std::ostream& operator<< (std::ostream& lhs, ExercisePlan& rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getSteps() << std::endl;
	lhs << rhs.getDate() << std::endl;

	return lhs;
}
// cin extraction
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
	std::cout << rhs.getPlanName() << ", " << rhs.getSteps() << ", " << rhs.getDate() << std::endl;

	return lhs;
}