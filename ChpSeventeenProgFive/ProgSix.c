#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LEN 20

int read_line(char str[], int n);
int compare_words(const void *p, const void *q);

int main(void)
{
    char *words[MAX_WORDS];
    char word[WORD_LEN + 1];
    int i, num_words = 0;

    for (;;)
    {
        if (num_words == MAX_WORDS)
        {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter word: ");
        read_line(word, WORD_LEN);

        /* Stop if the user enters an empty word */
        if (strlen(word) == 0)
            break;

        /* Allocate memory for the word */
        words[num_words] = malloc(strlen(word) + 1);

        if (words[num_words] == NULL)
        {
            printf("-- No space left --\n");
            break;
        }

        strcpy(words[num_words], word);
        num_words++;
    }

    /* Sort the array of pointers */
    qsort(words, num_words, sizeof(char *), compare_words);

    printf("\nIn sorted order:\n");

    for (i = 0; i < num_words; i++)
        printf("%s\n", words[i]);

    /* Free allocated memory */
    for (i = 0; i < num_words; i++)
        free(words[i]);

    return 0;
}

int compare_words(const void *p, const void *q)
{
    const char *const *word1 = (const char *const *)p;
    const char *const *word2 = (const char *const *)q;

    return strcmp(*word1, *word2);
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
