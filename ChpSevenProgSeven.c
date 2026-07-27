#include <stdio.h>

int main(void)
{
    int num1, den1, num2, den2;
    int result_num, result_den;
    char op;

    printf("Enter two fractions separated by an operator\n");
    printf("(example: 1/2+3/4): ");

    scanf("%d/%d %c %d/%d",
          &num1, &den1,
          &op,
          &num2, &den2);

    switch (op)
    {
        case '+':
            result_num = num1 * den2 + num2 * den1;
            result_den = den1 * den2;
            break;

        case '-':
            result_num = num1 * den2 - num2 * den1;
            result_den = den1 * den2;
            break;

        case '*':
            result_num = num1 * num2;
            result_den = den1 * den2;
            break;

        case '/':
            result_num = num1 * den2;
            result_den = den1 * num2;
            break;

        default:
            printf("Invalid operator.\n");
            return 1;
    }

    printf("Result = %d/%d\n", result_num, result_den);

    return 0;
}
