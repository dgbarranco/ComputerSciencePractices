#include <stdio.h>

#define MAX 100

int main(void)
{
    char message[MAX];
    int i = 0;

    printf("Enter a message: ");

    while ((message[i] = getchar()) != '\n' && i < MAX - 1)
        i++;

    printf("Reversal is: ");

    while (i > 0)
        putchar(message[--i]);

    printf("\n");

    return 0;
}
