#include <stdio.h>

float compute_tax(float income);

int main(void)
{
    float income;

    printf("Enter taxable income: ");
    scanf("%f", &income);

    printf("Tax due: %.2f\n", compute_tax(income));

    return 0;
}

float compute_tax(float income)
{
    if (income <= 750.00f)
        return income * 0.01f;

    else if (income <= 2250.00f)
        return 7.50f + (income - 750.00f) * 0.02f;

    else if (income <= 3750.00f)
        return 37.50f + (income - 2250.00f) * 0.03f;

    else if (income <= 5250.00f)
        return 82.50f + (income - 3750.00f) * 0.04f;

    else if (income <= 7000.00f)
        return 142.50f + (income - 5250.00f) * 0.05f;

    else
        return 230.00f + (income - 7000.00f) * 0.06f;
}
