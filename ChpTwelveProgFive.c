#include <stdio.h>

int main(void)
{
    char sentence[200];
    char *p = sentence;
    char end;

    printf("Enter a sentence: ");

    while (1)
    {
        scanf("%c", p);

        if (*p == '.' || *p == '?' || *p == '!')
        {
            end = *p;
            break;
        }

        p++;
    }

    char *last = p - 1;

    printf("Reversal of sentence: ");

    while (last >= sentence)
    {
        while (last >= sentence && *last != ' ')
            last--;

        char *start = last + 1;

        while (start < p && *start != ' ')
        {
            printf("%c", *start);
            start++;
        }

        if (last > sentence)
            printf(" ");

        last--;
    }

    printf("%c\n", end);

    return 0;
}
