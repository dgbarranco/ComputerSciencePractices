#include <stdio.h>

int main(void)
{
    float income, tax;

    printf("Enter your annual income: $");
    scanf("%f", &income);

    if (income <= 10000)
        tax = income * 0.10;
    else if (income <= 30000)
        tax = 10000 * 0.10 + (income - 10000) * 0.15;
    else
        tax = 10000 * 0.10 + 20000 * 0.15 +
              (income - 30000) * 0.20;

    printf("Income tax: $%.2f\n", tax);

    return 0;
}
