#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

int read_line(char str[], int n);

int main(void)
{
    char *words[MAX_WORDS];
    char temp[MAX_WORD_LEN + 1];
    char *p;
    int num_words = 0;
    int i, j;

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

    /* Sort the words alphabetically */
    for (i = 0; i < num_words - 1; i++)
    {
        for (j = i + 1; j < num_words; j++)
        {
            if (strcmp(words[i], words[j]) > 0)
            {
                char *temp_ptr = words[i];
                words[i] = words[j];
                words[j] = temp_ptr;
            }
        }
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
