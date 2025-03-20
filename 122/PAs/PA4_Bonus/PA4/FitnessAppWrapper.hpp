///////////////////////////////////////////////////////////////////////////////
/// \file         
/// \author       AO
/// \date         
/// \brief   You are to write a basic fitness application, in C++, 
///          that allows the user of the application to manually edit 
///          “diet” and “exercise” plans.For this application you will 
///          need to create three classes : DietPlan, ExercisePlan, and FitnessAppWrapper.     
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdlib> // to use system("cls");

#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // default constructor
	~FitnessAppWrapper(); // destructor

	void runApp(); // will drive the application
	void loadWeeklyDietPlan(); // this will call the private loadWeeklyPlan() function
	void storeWeeklyDietPlan(); // this will call the private storeWeeklyPlan() function
	void loadWeeklyExercisePlan(); // new
	void storeWeeklyExercisePlan(); // new

	void displayWeeklyDietPlan(); // this will call the private displayWeeklyPlan() function
	void displayWeeklyExercisePlan(); // new

private:
	DietPlan mDPList[7]; // will store the weekly list of DietPlan objects - 1 week = 7 days
	ExercisePlan mEPList[7]; // will store 7 exercise plans

	fstream mFstrDP;    // stream object for input/output to dietPlans.txt
	fstream mFstrEP;    // stream object for exercisePlans.txt input/output file

	// private helper/utility functions
	bool editDietPlan(); // will prompt the user for the name of the plan to edit
	bool editExercisePlan();  // new
	void performUserSelection(const int& option);
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);  // new
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);  // new
	void displayDailyPlan(const DietPlan& plan);
	void displayDailyPlan(const ExercisePlan& plan);  // new
	void displayWeeklyPlan(const DietPlan weeklyPlan[]);
	void displayWeeklyPlan(const ExercisePlan weeklyPlan[]);  // new
	void storeDailyPlan(fstream& fileStream, const DietPlan& plan);
	void storeDailyPlan(fstream& fileStream, const ExercisePlan& plan);  // new
	void storeWeeklyPlan(fstream& fileStream, const DietPlan weeklyPlan[]);
	void storeWeeklyPlan(fstream& fileStream, const ExercisePlan weeklyPlan[]);  // new

	void displayMenu();
};