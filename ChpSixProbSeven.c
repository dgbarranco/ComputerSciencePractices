#include <stdio.h>

int main(void)
{
    int n;
    int i;
    int odd;
    int square;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    odd = 3;
    square = 1;

    for (i = 1; i <= n; odd += 2, square += odd, i++)
        printf("%10d%10d\n", i, square);

    return 0;
}
