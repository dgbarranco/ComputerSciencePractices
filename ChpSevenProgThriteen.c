#include <stdio.h>

int main(void)
{
    char ch;
    int letters = 0;
    int words = 1;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
            words++;
        else
            letters++;
    }

    printf("Average word length: %.1f\n",
           (float) letters / words);

    return 0;
}
