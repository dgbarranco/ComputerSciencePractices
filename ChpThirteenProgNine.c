#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);

int main(void)
{
    char sentence[200];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("Your sentence contains %d vowels.\n",
           compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int vowels = 0;

    while (*sentence != '\0')
    {
        switch (tolower(*sentence))
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                break;
        }

        sentence++;
    }

    return vowels;
}
