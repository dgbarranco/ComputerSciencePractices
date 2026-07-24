#include <stdio.h>

#define MAX 100

int main(void)
{
    char message[MAX];
    char *p;

    printf("Enter a message: ");

    for (p = message; p < message + MAX - 1; p++)
    {
        *p = getchar();

        if (*p == '\n')
            break;
    }

    printf("Reversal is: ");

    while (p > message)
    {
        p--;
        putchar(*p);
    }

    printf("\n");

    return 0;
}
