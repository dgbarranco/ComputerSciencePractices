#include <stdio.h>

int main(void)
{
    double interest_rate, balance;
    int years;

    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter initial balance: ");
    scanf("%lf", &balance);

    printf("Enter number of years: ");
    scanf("%d", &years);

    interest_rate /= 1200.0;

    printf("\nYear     Balance\n");

    for (int year = 1; year <= years; year++) {

        for (int month = 1; month <= 12; month++)
            balance += balance * interest_rate;

        printf("%3d %12.2f\n", year, balance);
    }

    return 0;
}
