#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int vowels = 0;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n')
    {
        ch = tolower(ch);

        switch (ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                break;
        }
    }

    printf("Your sentence contains %d vowels.\n", vowels);

    return 0;
}
