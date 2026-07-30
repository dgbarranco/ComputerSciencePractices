#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

static int stack[STACK_SIZE];
static int top = 0;

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
