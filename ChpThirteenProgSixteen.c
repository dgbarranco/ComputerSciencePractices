#include <stdio.h>

#define MAX 100

void reverse(char *message);

int main(void)
{
    char message[MAX];
    char *p = message;

    printf("Enter a message: ");

    while ((*p = getchar()) != '\n' && p < message + MAX - 1)
        p++;

    *p = '\0';

    reverse(message);

    printf("Reversal is: %s\n", message);

    return 0;
}

void reverse(char *message)
{
    char *left = message;
    char *right = message;
    char temp;

    /* Move right pointer to the last character */
    while (*right != '\0')
        right++;

    right--;

    /* Reverse the string */
    while (left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}
