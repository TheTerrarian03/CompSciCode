#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

class FitnessAppWrapper {

	// data members
	DietPlan dietPlans[7];
	ExercisePlan exercisePlans[7];

	// member functions

	void loadDailyPlan(std::fstream& fileStream, DietPlan& plan);
	void loadDailyPlan(std::fstream& fileStream, ExercisePlan& plan);

	void loadWeeklyPlan(std::fstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(std::fstream& fileStream, ExercisePlan weeklyPlan[]);

	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);

	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayWeekylPlan(ExercisePlan weeklyPlan[]);

	void storeDailyPlan(std::ostream& outputStream, DietPlan& plan);
	void storeDailyPlan(std::ostream& outputStream, ExercisePlan& plan);

	void storeWeeklyPlan(std::ostream& outputStream, DietPlan& plan);
	void storeWeeklyPlan(std::ostream& outputStream, ExercisePlan& plan);

public:
	FitnessAppWrapper() {};

	void runApp(void);
	void displayMenu(void);
};

/* ----- Functions Definitions ----- */

void FitnessAppWrapper::runApp() {
	while (1) {
		displayMenu();

		int choice = 0;
		std::cin >> choice;

		std::cout << "Got choice: " << choice << std::endl;

		if (choice == 9) return;
	}
}

void FitnessAppWrapper::displayMenu() {
	std::cout << "Please enter an option:" << std::endl;
	std::cout << "  1. Load weekly diet plan from file" << std::endl;
	std::cout << "  2. Load weekly exercise plan from file" << std::endl;
	std::cout << "  3. Store weekly diet plan to file" << std::endl;
	std::cout << "  4. Store weekly exercise plan to file" << std::endl;
	std::cout << "  5. Display weekly diet plan to screen" << std::endl;
	std::cout << "  6. Display weekly exercise plan to scree" << std::endl;
	std::cout << "  7. Edit daily diet plan" << std::endl;
	std::cout << "  8. Edit daily exercise plan" << std::endl;
	std::cout << "  9. Exit" << std::endl;
}