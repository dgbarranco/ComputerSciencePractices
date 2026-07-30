#include <stdio.h>
#include "word.h"

int read_char(void)
{
    int ch = getchar();

    if (ch == '\n' || ch == '\t')
        return ' ';

    return ch;
}

void read_word(char *word, int len)
{
    int ch, pos = 0;
    int truncated = 0;

    /* Skip leading spaces */
    while ((ch = read_char()) == ' ')
        ;

    /* Read the word */
    while (ch != ' ' && ch != EOF)
    {
        if (pos < len - 1)
        {
            word[pos++] = ch;
        }
        else
        {
            truncated = 1;
        }

        ch = read_char();
    }

    /* Add * if the word was truncated */
    if (truncated && len > 1)
    {
        word[len - 2] = '*';
        word[len - 1] = '\0';
    }
    else
    {
        word[pos] = '\0';
    }
}
