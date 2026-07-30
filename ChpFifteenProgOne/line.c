#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  line[0] = '\0';
  line_len = 0;
  num_woprds = 0;
}

vopid add_word(const char *word)
{
  if(num_words = 0){
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i, j;
    static int left_to_right = 0;

    extra_spaces = MAX_LINE_LEN - line_len;

    for (i = 0; i < line_len; i++)
    {
        if (line[i] != ' ')
        {
            putchar(line[i]);
        }
        else
        {
            if (left_to_right)
            {
                /* Put larger gaps toward the beginning */
                spaces_to_insert =
                    (extra_spaces + num_words - 2) / (num_words - 1);
            }
            else
            {
                /* Put larger gaps toward the end */
                spaces_to_insert =
                    extra_spaces / (num_words - 1);
            }

            for (j = 0; j <= spaces_to_insert; j++)
                putchar(' ');

            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }

    putchar('\n');

    /* Alternate direction for the next line */
    left_to_right = !left_to_right;
}

void flush_line(void)
{
  if(line_len > 0){
    puts(line);
  }
}
