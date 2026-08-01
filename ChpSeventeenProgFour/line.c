#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node
{
    char *word;
    struct node *next;
};

static struct node *line = NULL;
static int line_len = 0;
static int num_words = 0;

void clear_line(void)
{
    struct node *p;

    while (line != NULL)
    {
        p = line;
        line = line->next;

        free(p->word);
        free(p);
    }

    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    struct node *new_node;
    struct node *p;

    new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Out of memory\n");
        exit(EXIT_FAILURE);
    }

    new_node->word = malloc(strlen(word) + 1);

    if (new_node->word == NULL)
    {
        printf("Out of memory\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->word, word);
    new_node->next = NULL;

    if (line == NULL)
    {
        line = new_node;
    }
    else
    {
        p = line;

        while (p->next != NULL)
            p = p->next;

        p->next = new_node;

        line_len++;      /* space before the new word */
    }

    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    struct node *p;
    int extra_spaces;
    int spaces_to_insert;
    int gaps;
    int i;

    if (line == NULL)
        return;

    extra_spaces = MAX_LINE_LEN - line_len;
    gaps = num_words - 1;

    p = line;

    while (p != NULL)
    {
        printf("%s", p->word);

        if (p->next != NULL)
        {
            spaces_to_insert =
                gaps > 0 ? extra_spaces / gaps : 0;

            for (i = 0; i <= spaces_to_insert; i++)
                putchar(' ');

            extra_spaces -= spaces_to_insert;
            gaps--;
        }

        p = p->next;
    }

    putchar('\n');

    clear_line();
}

void flush_line(void)
{
    struct node *p;

    p = line;

    while (p != NULL)
    {
        printf("%s", p->word);

        if (p->next != NULL)
            putchar(' ');

        p = p->next;
    }

    putchar('\n');

    clear_line();
}
