#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter a number (0-9999): ");
    scanf("%d", &number);

    if (number < 10)
        printf("The number has 1 digit.\n");
    else if (number < 100)
        printf("The number has 2 digits.\n");
    else if (number < 1000)
        printf("The number has 3 digits.\n");
    else
        printf("The number has 4 digits.\n");

    return 0;
}
