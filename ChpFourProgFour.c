#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter a decimal number (0-255): ");
    scanf("%d", &number);

    printf("Binary: ");

    printf("%d", (number / 128) % 2);
    printf("%d", (number / 64) % 2);
    printf("%d", (number / 32) % 2);
    printf("%d", (number / 16) % 2);
    printf("%d", (number / 8) % 2);
    printf("%d", (number / 4) % 2);
    printf("%d", (number / 2) % 2);
    printf("%d\n", number % 2);

    return 0;
}
