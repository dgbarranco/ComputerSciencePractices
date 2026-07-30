#include <stdio.h>

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[200];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("Average word length: %.1f\n",
           compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int letters = 0;
    int words = 0;
    int in_word = 0;

    while (*sentence != '\0')
    {
        if (*sentence == ' ' || *sentence == '\n' || *sentence == '\t')
        {
            if (in_word)
            {
                words++;
                in_word = 0;
            }
        }
        else
        {
            letters++;
            in_word = 1;
        }

        sentence++;
    }

    /* Count the last word if the sentence doesn't end with whitespace */
    if (in_word)
        words++;

    if (words == 0)
        return 0.0;

    return (double) letters / words;
}
