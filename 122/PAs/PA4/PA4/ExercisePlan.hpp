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
	ExercisePlan(int goal, std::string plan, std::string date);

	/* ----- Rule of Three ----- */
	// Copy constructor
	ExercisePlan(ExercisePlan& d);

	// Copy assignment constructor
	ExercisePlan& operator=(ExercisePlan& rhs);

	// Destructor
	~ExercisePlan();

	/* ----- Getters ----- */
	int getCalories();
	std::string getPlanName();
	std::string getDate();

	/* ----- Setters ----- */
	void setCalories(int calories);
	void setPlanName(std::string plan_name);
	void setDate(std::string date);
};

ExercisePlan::ExercisePlan() {
	goal_steps = 0;
	plan_name = "";
	date = "";
}

ExercisePlan::~ExercisePlan() {}