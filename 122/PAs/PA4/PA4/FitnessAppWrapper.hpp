#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

#define WEEK_LEN 7  // this shouldn't change unless you're not on earth or something went really wrong

class FitnessAppWrapper {

	/* ----- Data Members ----- */
	DietPlan dietPlans[WEEK_LEN];
	ExercisePlan exercisePlans[WEEK_LEN];

	/* ----- Main Private Member Functions ----- */

	void loadDailyPlan(std::fstream& fileStream, DietPlan& plan);
	void loadDailyPlan(std::fstream& fileStream, ExercisePlan& plan);

	void loadWeeklyPlan(std::fstream& fileStream, DietPlan weeklyPlan[WEEK_LEN]);
	void loadWeeklyPlan(std::fstream& fileStream, ExercisePlan weeklyPlan[WEEK_LEN]);

	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);

	void displayWeeklyPlan(DietPlan weeklyPlan[WEEK_LEN]);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[WEEK_LEN]);

	//void storeDailyPlan(std::ostream& outputStream, DietPlan& plan);
	//void storeDailyPlan(std::ostream& outputStream, ExercisePlan& plan);

	//void storeWeeklyPlan(std::ostream& outputStream, DietPlan& plan);
	//void storeWeeklyPlan(std::ostream& outputStream, ExercisePlan& plan);

	/* ----- Middle-man Private Member Functions ----- */
	void loadDiets();
	void loadExercises();

	void storeDiets();
	void storeExercises();

	void editDiets();
	void editExercises();

public:
	// constructor
	FitnessAppWrapper() {};
	// destructor - does nothing
	~FitnessAppWrapper() {};

	/* ----- Public Function Definitions ----- */
	void runApp(void);
	void displayMenu(void);
};

/* ----- Public Function Definitions ----- */

void FitnessAppWrapper::runApp() {
	while (1) {
		displayMenu();

		int choice = 0;
		std::cin >> choice;

		std::cout << "Got choice: " << choice << std::endl;

		if (choice == 1) loadDiets();
		if (choice == 2) loadExercises();
		// 3
		// 4
		if (choice == 5) displayWeeklyPlan(this->dietPlans);
		if (choice == 6) displayWeeklyPlan(this->exercisePlans);
		if (choice == 7) editDiets();
		if (choice == 8) editExercises();
		if (choice == 9) return;  // TODO: STORE
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

/* ----- Main Private Member Function Definitions ----- */

void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}
void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, DietPlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}
void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, ExercisePlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan& plan) {
	std::cout << plan;
}
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan) {
	std::cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}

//void FitnessAppWrapper::storeDailyPlan(std::ostream& outputStream, DietPlan& plan);
//void FitnessAppWrapper::storeDailyPlan(std::ostream& outputStream, ExercisePlan& plan);

//void FitnessAppWrapper::storeWeeklyPlan(std::ostream& outputStream, DietPlan& plan);
//void FitnessAppWrapper::storeWeeklyPlan(std::ostream& outputStream, ExercisePlan& plan);

/* ----- Middle-man Private Member Function Definitions ----- */
void FitnessAppWrapper::loadDiets() {
	// open input file and check for existence
	std::fstream infile;
	infile.open("dietPlans.txt", std::ios::in);

	if (!infile.is_open()) {
		std::cout << "There was an error opening the `dietPlans.txt` file!" << std::endl;
		infile.close();  // unnecessary? file not even open? but try closing anyways?
		return;
	}

	loadWeeklyPlan(infile, this->dietPlans);

	infile.close();
}
void FitnessAppWrapper::loadExercises() {
	// open input file and check for existence
	std::fstream infile;
	infile.open("exercisePlans.txt", std::ios::in);

	if (!infile.is_open()) {
		std::cout << "There was an error opening the `exercisePlans.txt` file!" << std::endl;
		infile.close();  // unnecessary here too?
		return;
	}

	loadWeeklyPlan(infile, this->exercisePlans);

	infile.close();
}

void FitnessAppWrapper::storeDiets() {}
void FitnessAppWrapper::storeExercises() {}

void FitnessAppWrapper::editDiets() {
	int edit_day = -1;

	// input verification loop for choice getting
	while (edit_day == -1) {
		std::string line;
		std::cout << "Enter a day's number to edit [1-" << WEEK_LEN << "], \"l\" to list current Diet Plans, or \"q\" to quit:" << std::endl;
		std::cout << "> ";

		std::cin >> line;

		if (line[0] == 'l') {
			displayWeeklyPlan(this->dietPlans);
			line = "";
			continue;
		}

		if (line[0] == 'q') {
			return;
		}

		edit_day = std::stoi(line);

		if (edit_day >= 1 && edit_day <= WEEK_LEN) break;

		std::cout << "Invalid input! Please try again!" << std::endl;

		edit_day = -1;
	}

	std::cout << std::endl << "Editing Day #" << edit_day << "..." << std::endl;

	edit_day -= 1;  // convert to array range

	// get new input from user

	int cals;
	std::string plan = "", date = "", tmp_cals = "";

	std::cout << "Enter new plan name (current: \"" << this->dietPlans[edit_day].getPlanName() << "\"): ";

	std::getline(std::cin, plan);  // huh? why does this make it work? I guess I'll leave it... ¯\_(ツ)_/¯
	std::getline(std::cin, plan);  // yes the duplicate it intentional. maybe this ^ was to remove any newlines leftover?

	std::cout << "Enter a new calorie goal (current: " << this->dietPlans[edit_day].getCalories() << "): ";

	std::getline(std::cin, tmp_cals);

	cals = std::stoi(tmp_cals);

	std::cout << "Enter a new date (current: " << this->dietPlans[edit_day].getDate() << "): ";

	std::getline(std::cin, date);

	std::cout << plan << ", " << cals << ", " << date << std::endl;

	// set input from user to plan
	this->dietPlans[edit_day].setCalories(cals);
	this->dietPlans[edit_day].setDate(date);
	this->dietPlans[edit_day].setPlanName(plan);

	std::cout << "Diet Plan for day #" << edit_day + 1 << " has ben updated!" << std::endl;
}
void FitnessAppWrapper::editExercises() {
	int edit_day = -1;

	// input verification loop for choice getting
	while (edit_day == -1) {
		std::string line;
		std::cout << "Enter a day's number to edit [1-" << WEEK_LEN << "], \"l\" to list current Exercise Plans, or \"q\" to quit:" << std::endl;
		std::cout << "> ";

		std::cin >> line;

		if (line[0] == 'l') {
			displayWeeklyPlan(this->exercisePlans);
			line = "";
			continue;
		}

		if (line[0] == 'q') {
			return;
		}

		edit_day = std::stoi(line);

		if (edit_day >= 1 && edit_day <= WEEK_LEN) break;

		std::cout << "Invalid input! Please try again!" << std::endl;

		edit_day = -1;
	}

	std::cout << std::endl << "Editing Day #" << edit_day << "..." << std::endl;

	edit_day -= 1;  // convert to array range

	// get new input from user

	int steps;
	std::string plan = "", date = "", tmp_steps = "";

	std::cout << "Enter new plan name (current: \"" << this->exercisePlans[edit_day].getPlanName() << "\"): ";

	std::getline(std::cin, plan);  // same stuff here
	std::getline(std::cin, plan);

	std::cout << "Enter a new steps goal (current: " << this->exercisePlans[edit_day].getSteps() << "): ";

	std::getline(std::cin, tmp_steps);

	steps = std::stoi(tmp_steps);

	std::cout << "Enter a new date (current: " << this->exercisePlans[edit_day].getDate() << "): ";

	std::getline(std::cin, date);

	std::cout << plan << ", " << steps << ", " << date << std::endl;

	// set input from user to plan
	this->exercisePlans[edit_day].setSteps(steps);
	this->exercisePlans[edit_day].setDate(date);
	this->exercisePlans[edit_day].setPlanName(plan);

	std::cout << "Exercise Plan for day #" << edit_day + 1 << " has ben updated!" << std::endl;
}
