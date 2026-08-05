#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LEN 20

int read_line(char str[], int n);

int main(void)
{
    char *words[MAX_WORDS];
    char word[WORD_LEN + 1];
    int i, j, num_words = 0;

    for (;;)
    {
        if (num_words == MAX_WORDS)
        {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter word: ");
        read_line(word, WORD_LEN);

        if (strlen(word) == 0)
            break;

        /* Find where the word belongs alphabetically */
        for (i = 0; i < num_words; i++)
        {
            if (strcmp(word, words[i]) < 0)
                break;
        }

        /* Shift pointers to make room */
        for (j = num_words; j > i; j--)
            words[j] = words[j - 1];

        /* Allocate memory for the new word */
        words[i] = malloc(strlen(word) + 1);

        if (words[i] == NULL)
        {
            printf("-- No space left --\n");
            break;
        }

        strcpy(words[i], word);
        num_words++;
    }

    printf("\nIn sorted order:\n");

    for (i = 0; i < num_words; i++)
        printf("%s\n", words[i]);

    /* Free allocated memory */
    for (i = 0; i < num_words; i++)
        free(words[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n)
            str[i++] = ch;
    }

    str[i] = '\0';
    return i;
}
