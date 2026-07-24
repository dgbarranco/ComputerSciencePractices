#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
    char message[MAX];
    char *p = message;
    char *left, *right;

    printf("Enter a message: ");

    while (p < message + MAX - 1)
    {
        char ch = getchar();

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
