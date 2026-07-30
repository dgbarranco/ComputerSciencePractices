#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = 0;

void push(int value);
int pop(void);
int is_empty(void);
int evaluate_RPN_expression(const char *expression);

int main(void)
{
    char expression[100];

    printf("Enter an RPN expression: ");
    fgets(expression, sizeof(expression), stdin);

    printf("Value of expression: %d\n",
           evaluate_RPN_expression(expression));

    return 0;
}

int evaluate_RPN_expression(const char *expression)
{
    char ch;

    top = 0;   /* Reset the stack */

    while ((ch = *expression++) != '\0')
    {
        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }
        else if (ch == '+')
        {
            int b = pop();
            int a = pop();
            push(a + b);
        }
        else if (ch == '-')
        {
            int b = pop();
            int a = pop();
            push(a - b);
        }
        else if (ch == '*')
        {
            int b = pop();
            int a = pop();
            push(a * b);
        }
        else if (ch == '/')
        {
            int b = pop();
            int a = pop();
            push(a / b);
        }
        else if (ch == '=')
        {
            int value = pop();

            if (!is_empty())
            {
                printf("Error: Invalid expression\n");
                exit(EXIT_FAILURE);
            }

            return value;
        }

        /* Ignore spaces and other characters */
    }

    printf("Error: No '=' found\n");
    exit(EXIT_FAILURE);
}

void push(int value)
{
    if (top == STACK_SIZE)
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stack[top++] = value;
}

int pop(void)
{
    if (top == 0)
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    return stack[--top];
}

int is_empty(void)
{
    return top == 0;
}
