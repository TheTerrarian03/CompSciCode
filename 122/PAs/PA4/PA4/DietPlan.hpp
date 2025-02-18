#pragma once

#include <string>

class DietPlan {

private:
	int goal_calories;
	std::string plan_name;
	std::string date;

public:
	/* ----- Constructors ----- */
	DietPlan();
	DietPlan(int goal, std::string plan, std::string date);

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
};

DietPlan::DietPlan() {
	goal_calories = 0;
	plan_name = "";
	date = "";
}

DietPlan::~DietPlan() {}