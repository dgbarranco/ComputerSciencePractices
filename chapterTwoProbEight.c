#include <stdio.h>

int main(void) {
    float loan, interestRate, monthlyPayment;
    float monthlyInterestRate;
    float balance;
    int month = 1;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);

    monthlyInterestRate = (interestRate / 100) / 12;

    balance = loan;

    while (month <= 3) {
        balance = balance * (1 + monthlyInterestRate) - monthlyPayment;

        if (month == 1) {
            printf("Balance remaining after first payment: $%.2f\n", balance);
        }
        else if (month == 2) {
            printf("Balance remaining after second payment: $%.2f\n", balance);
        }
        else {
            printf("Balance remaining after third payment: $%.2f\n", balance);
        }

        month++;
    }

    return 0;
}
