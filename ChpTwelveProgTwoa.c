#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
    char message[MAX];
    int i = 0;
    int left, right;

    printf("Enter a message: ");

    while ((message[i] = getchar()) != '\n' && i < MAX - 1)
    {
        if (isalpha(message[i]))
        {
            message[i] = tolower(message[i]);
            i++;
        }
    }

    left = 0;
    right = i - 1;

    while (left < right)
    {
        if (message[left] != message[right])
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
