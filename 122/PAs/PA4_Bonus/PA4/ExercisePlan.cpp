// similar story here, mirrored DietPlan.cpp's code,
// with changes to match what should be in a ExercisePlan
// class

// file finished by Logan Meyers on 03/19/2025

#include "ExercisePlan.hpp"

/* ----- Member Functions ----- */

// constructor
ExercisePlan::ExercisePlan(const string& newPlanName,
		const string& newDate,
		const int& newGoalSteps) {

	this->mPlanName = newPlanName;
	this->mDate = newDate;
	this->mGoalSteps = newGoalSteps;
	cout << "Inside ExercisePlan's constructor!" << endl;
}

// copy constructor
ExercisePlan::ExercisePlan(const ExercisePlan& copy) {
	this->mPlanName = copy.mPlanName;
	this->mDate = copy.mDate;
	this->mGoalSteps = copy.mGoalSteps;
}

// destructor
ExercisePlan::~ExercisePlan() {
	cout << "Inside of ExercisePlan's destructor" << endl;
}

// getters
string ExercisePlan::getPlanName() const { return this->mPlanName; }
string ExercisePlan::getDate() const { return this->mDate; }
int ExercisePlan::getGoalSteps() const { return this->mGoalSteps; }

// setters
void ExercisePlan::setPlanName(const string& newPlanName) { this->mPlanName = newPlanName; }
void ExercisePlan::setDate(const string& newDate) { this->mDate = newDate; }
void ExercisePlan::setGoalSteps(const int& newGoalSteps) { this->mGoalSteps = newGoalSteps; }

// edit function
void ExercisePlan::editGoal() {
	cout << "Please enter a new calories goal: ";
	cin >> this->mGoalSteps;

	cout << (*this) << endl;  // use overload to display new goal
}

/* ----- Non-Member Functions ----- */

// write to output stream
ostream& operator<< (ostream& lhs, const ExercisePlan& rhs) {
	lhs << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs;
}

// write to file stream
fstream& operator<< (fstream& lhs, const ExercisePlan& rhs) {
	// use some fancy casting for string reasons?
	((ofstream&)(lhs)) << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs;
}

// read from input stream
fstream& operator>> (fstream& lhs, ExercisePlan& rhs) {
	char tempString[100] = "";

	// plan name
	lhs.getline(tempString, 100);
	rhs.setPlanName(tempString);

	// goal steps
	int goalSteps = 0;
	lhs.getline(tempString, 100);
	goalSteps = atoi(tempString);
	rhs.setGoalSteps(goalSteps);

	// date
	lhs.getline(tempString, 100);
	rhs.setDate(tempString);

	return lhs;
}