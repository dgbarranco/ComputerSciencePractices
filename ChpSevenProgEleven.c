#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char first_initial, ch;

    printf("Enter a first and last name: ");

    while ((ch = getchar()) == ' ')
        ;

    first_initial = ch;

    while ((ch = getchar()) != ' ' && ch != '\n')
        ;

    while ((ch = getchar()) == ' ')
        ;

    while (ch != '\n')
    {
        putchar(ch);
        ch = getchar();
    }

    printf(", %c.\n", first_initial);

    return 0;
}
