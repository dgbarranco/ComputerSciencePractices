#include <stdio.h>

int main(void)
{
    char first, second, third;

    printf("Enter a three-digit number: ");

    scanf(" %c%c%c", &first, &second, &third);

    printf("The reversal is: %c%c%c\n", third, second, first);

    return 0;
}
