#include <stdio.h>

int main(void)
{
    int number;
    int hundreds, tens, ones;

    printf("Enter a three-digit number: ");
    scanf("%d", &number);

    hundreds = number / 100;
    tens = (number / 10) % 10;
    ones = number % 10;

    printf("The reversal is: %d%d%d\n", ones, tens, hundreds);

    return 0;
}
