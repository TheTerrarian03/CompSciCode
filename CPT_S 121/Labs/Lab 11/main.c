#include "lab11.h"

int main() {
    // variables
    Employee payroll[200]; // the input file may not exceed 200 employee records
    FILE *infile = fopen("payroll.txt", "r");  // open `payroll.txt` for reading
    double total_payment = 0.0, average_payment = 0.0, max_payment = 0.0, min_payment = 1000000;

    // read data from file and populate:
    // - array of Employee structs, and their corresponding data
    // - number of employees
    int employee_count = 0;
    while (!feof(infile)) {
        employee_count++;

        // read name
        read_name(infile, &payroll[employee_count-1]);
        
        // read type
        read_type(infile, &payroll[employee_count-1]);

        // read hours worked
        read_hours(infile, &payroll[employee_count-1]);

        // read pay rate
        read_payrate(infile, &payroll[employee_count-1]);
    }

    #ifdef DEBUG_MESSAGES
    printf("Employee Count: %d\n\n", employee_count);
    #endif

    // close input file
    fclose(infile);

    // for loop to loop through each employee's payments
    for (int i=0; i < employee_count; i++) {
        // calc payment
        double payment = calc_payment(payroll[i].title, payroll[i].payrate, payroll[i].hours_worked);
        payroll[i].payment = payment;
        
        // add to total
        total_payment += payment;

        // update mins/maxes if necessary
        if (payment < min_payment) min_payment = payment;
        if (payment > max_payment) max_payment = payment;
    }

    // calc average
    average_payment = total_payment/employee_count;

    // debug info table about employees
    #ifdef DEBUG_MESSAGES
    printf     ("--+ EMPLOYEE DATA +---------------------\n");
    printf     ("# | Attr.         | Value\n");
    printf     ("--+---------------+---------------------\n");
    for (int i=0; i < employee_count; i++) {
        printf("%d | Name          | %s\n", i+1, payroll[i].name);
        printf("%d | Title         | %c\n", i+1, payroll[i].title);
        printf("%d | Hours Worked  | %.2lf\n", i+1, payroll[i].hours_worked);
        printf("%d | Payrate       | %.2lf\n", i+1, payroll[i].payrate);
        printf("%d | Payment       | %.2lf\n", i+1, payroll[i].payment);

        if (i < employee_count-1) printf("--+---------------+---------------------\n");
        else printf("\n");
    }
    #endif

    // open paid.txt for writing
    FILE *outfile = fopen("paid.txt", "w");

    // debug info about results
    #ifdef DEBUG_MESSAGES
    printf("Total:   $%.2lf\n", total_payment);
    printf("Average: $%.2lf\n", average_payment);
    printf("Min:     $%.2lf\n", min_payment);
    printf("Max:     $%.2lf\n\n", max_payment);
    #endif

    fprintf(outfile, "Total: $%lf\n", total_payment);
    fprintf(outfile, "Average: $%lf\n", average_payment);
    fprintf(outfile, "Min: $%lf\n", min_payment);
    fprintf(outfile, "Max: $%lf", max_payment);

    // close output file
    fclose(outfile);

    printf("-- Data computed and output to \"paid.txt\" successfully. --\n\n");

    return 0;
}
