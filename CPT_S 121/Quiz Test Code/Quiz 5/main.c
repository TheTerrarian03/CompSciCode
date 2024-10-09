#include <stdio.h>

// precondition: withdrawal amount must be a multiple of 10
// return: 1 if the balance >= withdrawal_amount; 0 otherwise
int dispense_bills(double balance, double withdrawal_amount,
			       int *hundreds_ptr, int *fifties_ptr, int *twenties_ptr, 
                   int *tens_ptr)
{
	int temp_withdrawal_amount = withdrawal_amount;
    if (balance >= withdrawal_amount) {
        *hundreds_ptr = (int)(withdrawal_amount / 100);
        temp_withdrawal_amount -= temp_withdrawal_amount / 100;
        printf("- %d\n", temp_withdrawal_amount);

        *fifties_ptr = (int)(temp_withdrawal_amount / 50);
        temp_withdrawal_amount = (temp_withdrawal_amount / 50);
        printf("- %d\n", temp_withdrawal_amount);

        *twenties_ptr = (int)(temp_withdrawal_amount / 20);
        temp_withdrawal_amount = (temp_withdrawal_amount / 20);
        printf("- %d\n", temp_withdrawal_amount);

        *tens_ptr = (int)(temp_withdrawal_amount / 10);
        temp_withdrawal_amount = (temp_withdrawal_amount / 10);
        printf("- %d\n", temp_withdrawal_amount);

        return 1;
    } else {
        return 0;
    }
}

// precondition: withdrawal amount must be a multiple of 10
// return: 1 if the balance >= withdrawal_amount; 0 otherwise
int dispense_bills(double balance, double withdrawal_amount,
			       int *hundreds_ptr, int *fifties_ptr, int *twenties_ptr, 
                   int *tens_ptr)
{
	// return 0 if user wants to withdraw more than they have
    if (withdrawal_amount > balance) return 0;

    // hundreds
    *hundreds_ptr = (int)(withdrawal_amount / 100);
    withdrawal_amount -= 100 * *hundreds_ptr;

    // fifties
    *fifties_ptr = (int)(withdrawal_amount / 50);
    withdrawal_amount -= 50 * *fifties_ptr;

    // twenties
    *twenties_ptr = (int)(withdrawal_amount / 20);
    withdrawal_amount -= 20 * *twenties_ptr;

    // tens
    *tens_ptr = (int)(withdrawal_amount / 10);

    // successful, return 1
    return 1;
}

int main() {
    double balance = 0.0, withdrawal_amount = 0.0;
	int hundreds = 0, fifties = 0, twenties = 0, tens = 0, result = 0;
	
	printf("Enter your bank balance: ");
	scanf("%lf", &balance);
	printf("Enter the amount to withdraw in multiples of 10s: ");
	scanf("%lf", &withdrawal_amount);

    // write the function call below
    dispense_bills(balance, withdrawal_amount, &hundreds, &fifties, &twenties, &tens);

    printf("100's: %d\n50's: %d\n20's: %d\n10's: %d\n", hundreds, fifties, twenties, tens);

    return 0;
}