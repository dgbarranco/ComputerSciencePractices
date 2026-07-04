#include <stdio.h>

int main(void)
{
    int m1, d1, y1;
    int m2, d2, y2;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);

    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    if (y1 < y2)
        printf("First date is earlier.\n");
    else if (y1 > y2)
        printf("Second date is earlier.\n");
    else if (m1 < m2)
        printf("First date is earlier.\n");
    else if (m1 > m2)
        printf("Second date is earlier.\n");
    else if (d1 < d2)
        printf("First date is earlier.\n");
    else if (d1 > d2)
        printf("Second date is earlier.\n");
    else
        printf("The dates are the same.\n");

    return 0;
}
