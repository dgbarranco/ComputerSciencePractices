#include <stdio.h>

int main(void)
{
    double number;
    double largest = 0.0;

    while (1)
    {
        printf("Enter a number: ");
        scanf("%lf", &number);

        if (number <= 0)
            break;

        if (number > largest)
            largest = number;
    }

    printf("The largest number entered was %.2f\n", largest);

    return 0;
}
