
#include <stdio.h>

int main(void)
{
    int number;
    int tens, ones;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    tens = number / 10;
    ones = number % 10;

    printf("The reversal is: %d%d\n", ones, tens);

    return 0;
}
