#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, y = 1.0, old_y;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    do
    {
        old_y = y;
        y = (old_y + x / old_y) / 2;
    }
    while (fabs(old_y - y) >= 0.00001 * y);

    printf("Square root: %.5f\n", y);

    return 0;
}
