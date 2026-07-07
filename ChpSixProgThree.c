#include <stdio.h>

int main(void)
{
    int numerator, denominator;
    int m, n, remainder, gcd;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    m = numerator;
    n = denominator;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    gcd = m;

    printf("In lowest terms: %d/%d\n",
           numerator / gcd,
           denominator / gcd);

    return 0;
}
