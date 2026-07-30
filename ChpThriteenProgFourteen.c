#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[100], word2[100];

    printf("Enter first word: ");
    scanf("%99s", word1);

    printf("Enter second word: ");
    scanf("%99s", word2);

    if (are_anagrams(word1, word2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int letters[26] = {0};

    while (*word1)
    {
        if (isalpha(*word1))
            letters[toupper(*word1) - 'A']++;

        word1++;
    }

    while (*word2)
    {
        if (isalpha(*word2))
            letters[toupper(*word2) - 'A']--;

        word2++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (letters[i] != 0)
            return false;
    }

    return true;
}
