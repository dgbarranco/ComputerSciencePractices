#include <stdio.h>

#define MAX_WORDS 30
#define MAX_LENGTH 20

int main(void)
{
    char words[MAX_WORDS][MAX_LENGTH + 1];
    char ch, end;
    int word = 0, letter = 0;

    printf("Enter a sentence: ");

    while (1)
    {
        scanf("%c", &ch);

        if (ch == '.' || ch == '?' || ch == '!')
        {
            words[word][letter] = '\0';
            end = ch;
            word++;
            break;
        }
        else if (ch == ' ')
        {
            words[word][letter] = '\0';
            word++;
            letter = 0;
        }
        else
        {
            if (letter < MAX_LENGTH)
            {
                words[word][letter] = ch;
                letter++;
            }
        }
    }

    printf("Reversal of sentence: ");

    for (int i = word - 1; i >= 0; i--)
    {
        printf("%s", words[i]);

        if (i > 0)
            printf(" ");
    }

    printf("%c\n", end);

    return 0;
}
