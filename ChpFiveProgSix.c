#include <stdio.h>

int main(void)
{
    int code;
    int d1, d2, d3, d4;

    printf("Enter a four-digit code: ");
    scanf("%d", &code);

    d1 = code / 1000;
    d2 = (code / 100) % 10;
    d3 = (code / 10) % 10;
    d4 = code % 10;

    if (d1 == d4 && d2 == d3)
        printf("Valid code.\n");
    else
        printf("Invalid code.\n");

    return 0;
}
