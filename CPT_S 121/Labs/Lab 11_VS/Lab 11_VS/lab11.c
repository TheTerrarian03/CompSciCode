#include "lab11.h"

void read_name(FILE *infile, Employee *emp) {
    // full name and last name segment
    char name[100];
    char last_name[50];

    // scanf first and last name into strings
    fscanf(infile, "%s", &name);
    fscanf(infile, "%s", &last_name);

    // cat space and last name to full name
    strcat(&name, " ");
    strcat(&name, &last_name);

    // copy full name into employee's name
    strcpy(emp->name, name);
}
void read_type(FILE *infile, Employee *emp) {
    char title[10];
    fscanf(infile, "%s", &title);
    emp->title = title[0];
}
void read_hours(FILE *infile, Employee *emp) {
    double hours = 0.0;
    fscanf(infile, "%lf", &hours);
    emp->hours_worked = hours;
}
void read_payrate(FILE *infile, Employee *emp) {
    double payrate = 0.0;
    fscanf(infile, "%lf", &payrate);
    emp->payrate = payrate;    
}

double calc_payment(char title, double payrate, double hours) {
    double payment;
    
    if (title == 'B') {
        if (hours <= 80) {
            payment = hours * payrate;
        } else if (hours > 80) {
            payment = 80 * payrate;
            payment += ((1.5 * payrate) * (hours - 80));
        }
    } else if (title == 'M') {
        if (hours <= 80) {
            payment = hours * payrate;
        } else if (hours > 80) {
            payment = 80 * payrate;
            payment += ((1.8 * payrate) * (hours - 80));
        }
    }

    return payment;
}