#include <stdio.h>

int main(void)
{
    int num1, den1;
    int num2, den2;
    int resultNum, resultDen;

    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d",
          &num1,
          &den1,
          &num2,
          &den2);

    resultNum = num1 * den2 + num2 * den1;
    resultDen = den1 * den2;

    printf("The sum is %d/%d\n", resultNum, resultDen);

    return 0;
}
