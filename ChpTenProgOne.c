#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = 0;

/* Push a character onto the stack */
void push(char ch)
{
    if (top < STACK_SIZE)
        stack[top++] = ch;
}

/* Pop a character from the stack */
char pop(void)
{
    if (top > 0)
        return stack[--top];

    return '\0';
}

/* Check if stack is empty */
bool is_empty(void)
{
    return top == 0;
}

int main(void)
{
    char ch;
    char open;
    bool matched = true;

    printf("Enter parentheses/braces/brackets: ");

    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (is_empty())
            {
                matched = false;
                break;
            }

            open = pop();

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
            {
                matched = false;
                break;
            }
        }
    }

    if (!is_empty())
        matched = false;

    if (matched)
        printf("Parentheses/braces are nested properly.\n");
    else
        printf("Parentheses/braces are NOT nested properly.\n");

    return 0;
}
