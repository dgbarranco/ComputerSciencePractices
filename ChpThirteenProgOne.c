#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[100];
    char smallest_word[100];
    char largest_word[100];

    /* Read the first word */
    printf("Enter word: ");
    scanf("%99s", word);

    /* Initialize smallest and largest */
    strcpy(smallest_word, word);
    strcpy(largest_word, word);

    /* If the first word is not 4 letters, continue reading */
    while (strlen(word) != 4)
    {
        printf("Enter word: ");
        scanf("%99s", word);

        /* Compare with smallest */
        if (strcmp(word, smallest_word) < 0)
            strcpy(smallest_word, word);

        /* Compare with largest */
        if (strcmp(word, largest_word) > 0)
            strcpy(largest_word, word);
    }

    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}
