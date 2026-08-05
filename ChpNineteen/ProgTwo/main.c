#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    char ch;
    int value;
    int a, b;

    make_empty();

    printf("Enter an RPN expression: ");

    while ((ch = getchar()) != '\n')
    {
        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }
        else if (ch == '+')
        {
            b = pop();
            a = pop();
            push(a + b);
        }
        else if (ch == '-')
        {
            b = pop();
            a = pop();
            push(a - b);
        }
        else if (ch == '*')
        {
            b = pop();
            a = pop();
            push(a * b);
        }
        else if (ch == '/')
        {
            b = pop();
            a = pop();
            push(a / b);
        }
        else if (ch == '=')
        {
            value = pop();

            if (!is_empty())
            {
                printf("Error: Invalid expression\n");
                return 1;
            }

            printf("Value of expression: %d\n", value);
            return 0;
        }

        /* Ignore spaces */
    }

    return 0;
}
