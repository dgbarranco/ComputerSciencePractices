#include <stdio.h>

int main(void)
{
    double weight;
    double cost;

    printf("Enter package weight: ");
    scanf("%lf", &weight);

    if (weight <= 5)
        cost = 5.00;
    else if (weight <= 15)
        cost = 10.00;
    else if (weight <= 30)
        cost = 18.00;
    else
        cost = 25.00;

    printf("Shipping cost: $%.2f\n", cost);

    return 0;
}
