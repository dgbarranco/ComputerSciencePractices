#include <stdio.h>

#define MAX 100

int main(void)
{
    char message[MAX];
    char *p = message;

    printf("Enter a message: ");

    while ((*p = getchar()) != '\n' && p < message + MAX - 1)
        p++;

    printf("Reversal is: ");

    while (p > message)
    {
        p--;
        putchar(*p);
    }

    printf("\n");

    return 0;
}
