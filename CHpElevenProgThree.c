#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void reduce(int numerator,
            int denominator,
            int *reduced_numerator,
            int *reduced_denominator);

int main(void)
{
    int num, den;
    int rnum, rden;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);

    reduce(num, den, &rnum, &rden);

    printf("Lowest terms: %d/%d\n", rnum, rden);

    return 0;
}

void reduce(int numerator,
            int denominator,
            int *reduced_numerator,
            int *reduced_denominator)
{
    int divisor = gcd(numerator, denominator);

    *reduced_numerator = numerator / divisor;
    *reduced_denominator = denominator / divisor;
}
