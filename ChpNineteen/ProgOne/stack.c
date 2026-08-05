#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 100

static char contents[STACK_SIZE];
static int top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full())
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    contents[top++] = ch;
}

char pop(void)
{
    if (is_empty())
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    return contents[--top];
}
