#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = 0;

void push(int value);
int pop(void);
int is_empty(void);

int main(void)
{
    char ch;
    int value;

    printf("Enter an RPN expression: ");

    while ((ch = getchar()) != '\n')
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
