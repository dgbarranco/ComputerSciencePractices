#include <stdio.h>

int main(void)
{
    double value, number;
    char op;

    printf("Enter an expression: ");

    scanf("%lf", &value);

    while (scanf(" %c %lf", &op, &number) == 2)
    {
        switch (op)
        {
            case '+':
                value += number;
                break;

            case '-':
                value -= number;
                break;

            case '*':
                value *= number;
                break;

            case '/':
                value /= number;
                break;
        }
    }

    printf("Value of expression: %.1f\n", value);

    return 0;
}
