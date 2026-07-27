#include <stdio.h>

int main(void)
{
    double n, sum = 0.0;

    printf("This program sums a series of doubles.\n");
    printf("Enter doubles (0 to stop): ");

    scanf("%lf", &n);

    while (n != 0) {
        sum += n;
        scanf("%lf", &n);
    }

    printf("The sum is %.2f\n", sum);

    return 0;
}
