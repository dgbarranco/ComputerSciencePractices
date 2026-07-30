#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_name(char *name);

int main(void)
{
    char name[100];

    printf("Enter a first and last name: ");
    fgets(name, sizeof(name), stdin);

    reverse_name(name);

    printf("%s\n", name);

    return 0;
}

void reverse_name(char *name)
{
    char first_initial;
    char last_name[100];
    int i = 0, j = 0;

    /* Skip leading spaces */
    while (isspace(name[i]))
        i++;

    /* Save first initial */
    first_initial = name[i];

    /* Skip first name */
    while (name[i] != '\0' && !isspace(name[i]))
        i++;

    /* Skip spaces between names */
    while (isspace(name[i]))
        i++;

    /* Copy last name */
    while (name[i] != '\0' && name[i] != '\n')
    {
        last_name[j++] = name[i++];
    }
    last_name[j] = '\0';

    /* Remove trailing spaces from last name */
    while (j > 0 && isspace(last_name[j - 1]))
    {
        last_name[j - 1] = '\0';
        j--;
    }

    /* Rewrite original string */
    sprintf(name, "%s, %c.", last_name, first_initial);
}
