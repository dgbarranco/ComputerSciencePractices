#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

int read_line(char str[], int n);
int compare_words(const void *p, const void *q);

int main(void)
{
    char *words[MAX_WORDS];
    char temp[MAX_WORD_LEN + 1];
    char *p;
    int num_words = 0;
    int i;

    for (;;)
    {
        printf("Enter word: ");
        read_line(temp, MAX_WORD_LEN);

        if (strlen(temp) == 0)
            break;

        p = malloc(strlen(temp) + 1);

        if (p == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        strcpy(p, temp);
        words[num_words++] = p;
    }

    /* Sort the array of pointers */
    qsort(words,
          num_words,
          sizeof(char *),
          compare_words);

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
    const char *const *word1 = p;
    const char *const *word2 = q;

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
