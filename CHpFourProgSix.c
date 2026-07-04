#include <stdio.h>

int main(void)
{
    int pin;
    int d1, d2, d3, d4;
    int sum;

    printf("Enter a four-digit PIN: ");
    scanf("%d", &pin);

    d1 = pin / 1000;
    d2 = (pin / 100) % 10;
    d3 = (pin / 10) % 10;
    d4 = pin % 10;

    sum = d1 + d2 + d3 + d4;

    if (sum % 10 == 0)
        printf("PIN appears valid.\n");
    else
        printf("PIN appears invalid.\n");

    return 0;
}
