#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main(void)
{
    char ch;
    char open;
    bool matched = true;

    make_empty();

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
        printf("Parentheses/braces/brackets are nested properly.\n");
    else
        printf("Parentheses/braces/brackets are NOT nested properly.\n");

    return 0;
}
