// The ExercisePlan class is very similar to the DietPlan class,
// so I've pretty much mirrored the functionality of the DietPlan
// to here, then made the necessary adjustments.

// file finished by Logan Meyers on 03/19/2025

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class ExercisePlan
{
public:
	// constructor w/ default arguments
	ExercisePlan(const string& newPlanName = "",
		const string& newDate = "",
		const int& newGoalSteps = 0);

	// copy constructor
	ExercisePlan(const ExercisePlan& copy);

	// destructor
	~ExercisePlan();

	/* ----- getters ----- */
	string getPlanName() const;
	string getDate() const;
	int getGoalSteps() const;

	/* ----- setters ----- */
	void setPlanName(const string& newPlanName);
	void setDate(const string& newDate);
	void setGoalSteps(const int& newGoalSteps);

	// prompt new goals, display new goals
	void editGoal();

private:
	string mPlanName;
	string mDate;
	int mGoalSteps;
};

/* ----- non-member functions ----- */

// write to output stream
ostream& operator<< (ostream& lhs, const ExercisePlan& rhs);

// write to file stream
fstream& operator<< (fstream& lhs, const ExercisePlan& rhs);

// read from input stream
fstream& operator>> (fstream& lhs, ExercisePlan& rhs);
