/*
- Logan Meyers
- 09/19/2024
- Lab 4, Section #12
- Task 2

- Description: This is my solution for Task 2, calculating a baseball player's bonuses
*/

#include "lab4.h"

double ask_prompt_and_add_conditionally(char* prompt, double add_amount);

int main() {
	double bonus_amount = 0.0;

	bonus_amount += ask_prompt_and_add_conditionally("All-Star Game appearance? (y/n): ", 25000.0);
	bonus_amount += ask_prompt_and_add_conditionally("All-Star Game appearance? (y/n): ", 25000.0);
	bonus_amount += ask_prompt_and_add_conditionally("All-Star Game appearance? (y/n): ", 25000.0);
	bonus_amount += ask_prompt_and_add_conditionally("All-Star Game appearance? (y/n): ", 25000.0);
	bonus_amount += ask_prompt_and_add_conditionally("All-Star Game appearance? (y/n): ", 25000.0);
	bonus_amount += ask_prompt_and_add_conditionally("All-Star Game appearance? (y/n): ", 25000.0);
	bonus_amount += ask_prompt_and_add_conditionally("All-Star Game appearance? (y/n): ", 25000.0);
	bonus_amount += ask_prompt_and_add_conditionally("All-Star Game appearance? (y/n): ", 25000.0);
	
	printf("YOUR MOM: %lf", bonus_amount);

	return 0;
}

double ask_prompt_and_add_conditionally(char* prompt, double add_amount) {
	char response = '\0';
	
	printf("%s", prompt);

	scanf(" %c", &response);

	if (response == 'y') {
		return add_amount;
	}
	else {
		return 0.0;
	}
}