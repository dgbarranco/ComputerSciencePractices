#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
    char message[MAX];
    char *p, *left, *right;
    char ch;

    printf("Enter a message: ");

    p = message;

    while (p < message + MAX - 1)
    {
        ch = getchar();

        if (ch == '\n')
            break;

        if (isalpha(ch))
            *p++ = tolower(ch);
    }

    left = message;
    right = p - 1;

    while (left < right)
    {
        if (*left != *right)
        {
            printf("Not a palindrome\n");
            return 0;
        }

        left++;
        right--;
    }

    printf("Palindrome\n");

    return 0;
}
