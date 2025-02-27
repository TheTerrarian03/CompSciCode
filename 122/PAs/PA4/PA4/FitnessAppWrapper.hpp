/*
- Name: Logan Meyers
- TA: Martin (M.H.) Hundrup
- Assignment: PA 4
- Finished: 02/26/2025
- Description: Virtual Gym Calender!

- File: FitnessAppWrapper.hpp
- Description: The headers and definitions for the main Fitness App Wrapper
*/

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

	void storeDailyPlan(std::fstream& outputStream, DietPlan& plan);
	void storeDailyPlan(std::fstream& outputStream, ExercisePlan& plan);

	void storeWeeklyPlan(std::fstream& outputStream, DietPlan weeklyPlan[WEEK_LEN]);
	void storeWeeklyPlan(std::fstream& outputStream, ExercisePlan weeklyPlan[WEEK_LEN]);

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

/*
 * Function: runApp
 * --------------------
 *   Runs the main menu and calls the necessary functions
 *
*/
void FitnessAppWrapper::runApp() {
	while (1) {
		displayMenu();

		int choice = 0;
		std::cin >> choice;

		if (choice == 1) loadDiets();
		if (choice == 2) loadExercises();
		if (choice == 3) storeDiets();
		if (choice == 4) storeExercises();
		if (choice == 5) displayWeeklyPlan(this->dietPlans);
		if (choice == 6) displayWeeklyPlan(this->exercisePlans);
		if (choice == 7) editDiets();
		if (choice == 8) editExercises();
		if (choice == 9) {
			storeDiets();
			storeExercises();
			return;
		}

		std::cout << std::endl;
	}
}

/*
 * Function: displayMenu
 * --------------------
 *   Simply displays a 9-item menu for the user to choose from
 *
*/
void FitnessAppWrapper::displayMenu() {
	std::cout << std::endl;
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
	std::cout << "> ";
}

/* ----- Main Private Member Function Definitions ----- */

/*
 * Function: loadDailyPlan
 * --------------------
 *   [DietPlan] Loads a plan from the given file stream
 *
 *   Parameters:
 *   - fileStream: the file stream to READ from
 *
*/
void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}

/*
 * Function: loadDailyPlan
 * --------------------
 *   [ExercisePlan] Loads a plan from the given file stream
 *
 *   Parameters:
 *   - fileStream: the file stream to READ from
 *
*/
void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}

/*
 * Function: loadWeeklyPlan
 * --------------------
 *   [DietPlan] Loads a plan from the given file stream
 *
 *   Parameters:
 *   - fileStream: the file stream to READ from
 *   - weeklyPlan: the array to write plans to
 *
*/
void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, DietPlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

/*
 * Function: loadWeeklyPlan
 * --------------------
 *   [ExercisePlan] Loads a plan from the given file stream
 *
 *   Parameters:
 *   - fileStream: the file stream to READ from
 *   - weeklyPlan: the array to write plans to
 *
*/
void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, ExercisePlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

/*
 * Function: displayDailyPlan
 * --------------------
 *   [DietPlan] Displays a plan to the screen
 *
 *   Parameters:
 *   - plan: the plan to display
 *
*/
void FitnessAppWrapper::displayDailyPlan(DietPlan& plan) {
	std::cout << plan;
}

/*
 * Function: displayDailyPlan
 * --------------------
 *   [ExercisePlan] Displays a plan to the screen
 *
 *   Parameters:
 *   - plan: the plan to display
 *
*/
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan) {
	std::cout << plan;
}

/*
 * Function: displayWeeklyPlan
 * --------------------
 *   [DietPlan] Displays a week's worth of plans to the screen
 *
 *   Parameters:
 *   - plan: the array of plans to display
 *
*/
void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		std::cout << "----- Diet for Day #" << i+1 << " -----" << std::endl;
		displayDailyPlan(weeklyPlan[i]);
	}
}

/*
 * Function: displayWeeklyPlan
 * --------------------
 *   [ExercisePlan] Displays a week's worth of plans to the screen
 *
 *   Parameters:
 *   - plan: the array of plans to display
 *
*/
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		std::cout << "----- Exercise for Day #" << i+1 << " -----" << std::endl;
		displayDailyPlan(weeklyPlan[i]);
	}
}

/*
 * Function: storeDailyPlan
 * --------------------
 *   [DietPlan] Stores the loaded plans to the given file stream
 *
 *   Parameters:
 *   - outputStream: the file stream to WRITE to
 *   - plan: the plan to store
 *
*/
void FitnessAppWrapper::storeDailyPlan(std::fstream& outputStream, DietPlan& plan) {
	outputStream << plan;
	outputStream << std::endl;
}

/*
 * Function: storeDailyPlan
 * --------------------
 *   [ExercisePlan] Stores the loaded plans to the given file stream
 *
 *   Parameters:
 *   - outputStream: the file stream to WRITE to
 *   - plan: the plan to store
 *
*/
void FitnessAppWrapper::storeDailyPlan(std::fstream& outputStream, ExercisePlan& plan) {
	outputStream << plan;
	outputStream << std::endl;
}

/*
 * Function: storeWeeklyPlan
 * --------------------
 *   [DietPlan] Stores a week's worth of loaded plans to the given file stream
 *
 *   Parameters:
 *   - outputStream: the file stream to WRITE to
 *   - plan: the array of plans to store
*/
void FitnessAppWrapper::storeWeeklyPlan(std::fstream& outputStream, DietPlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		storeDailyPlan(outputStream, weeklyPlan[i]);
	}
}

/*
 * Function: storeWeeklyPlan
 * --------------------
 *   [ExercisePlan] Stores a week's worth of loaded plans to the given file stream
 *
 *   Parameters:
 *   - outputStream: the file stream to WRITE to
 *   - plan: the array of plans to store
*/
void FitnessAppWrapper::storeWeeklyPlan(std::fstream& outputStream, ExercisePlan weeklyPlan[WEEK_LEN]) {
	for (int i = 0; i < WEEK_LEN; i++) {
		storeDailyPlan(outputStream, weeklyPlan[i]);
	}
}

/* ----- Middle-man Private Member Function Definitions ----- */

/*
 * Function: loadDiets
 * --------------------
 *   Main function to load all the diets from the dietPlans.txt file
 *
*/
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

	std::cout << "Diets loaded!" << std::endl;
}

/*
 * Function: loadExercises
 * --------------------
 *   Main function to load all the exercises from the exercisePlans.txt file
 *
*/
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

	std::cout << "Exercises loaded!" << std::endl;
}

/*
 * Function: storeDiets
 * --------------------
 *   Main function to store all the diets to the dietPlans.txt file
 *
*/
void FitnessAppWrapper::storeDiets() {
	// open input file and check for existence
	std::fstream outfile;
	outfile.open("dietPlans.txt", std::ios::out);

	if (!outfile.is_open()) {
		std::cout << "There was an error opening the `dietPlans.txt` file!" << std::endl;
		outfile.close();  // unnecessary? file not even open? but try closing anyways?
		return;
	}

	storeWeeklyPlan(outfile, this->dietPlans);

	outfile.close();

	std::cout << "Diets stored!" << std::endl;
}

/*
 * Function: storeExercises
 * --------------------
 *   Main function to store all the exercises to the exercisePlans.txt file
 *
*/
void FitnessAppWrapper::storeExercises() {
	// open input file and check for existence
	std::fstream outfile;
	outfile.open("exercisePlans.txt", std::ios::out);

	if (!outfile.is_open()) {
		std::cout << "There was an error opening the `exercisePlans.txt` file!" << std::endl;
		outfile.close();  // unnecessary? file not even open? but try closing anyways?
		return;
	}

	storeWeeklyPlan(outfile, this->exercisePlans);

	outfile.close();

	std::cout << "Exercises loaded!" << std::endl;
}

/*
 * Function: editDiets
 * --------------------
 *   Main function to edit a chosen diet that is currently loaded
 *
*/
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
	this->dietPlans[edit_day].editPlan();

	std::cout << "Diet Plan for day #" << edit_day + 1 << " has ben updated!" << std::endl;
}

/*
 * Function: editExercises
 * --------------------
 *   Main function to edit a chosen exercise that is currently loaded
 *
*/
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
	this->exercisePlans[edit_day].editPlan();

	std::cout << "Exercise Plan for day #" << edit_day + 1 << " has ben updated!" << std::endl;
}
