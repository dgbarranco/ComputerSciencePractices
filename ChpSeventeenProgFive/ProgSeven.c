#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

typedef struct {
    char *str;
    int len;
} vstring;

int read_line(char str[], int n);

int main(void)
{
    vstring *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN + 1];
    char temp[MSG_LEN + 3];
    int day, i, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);

        if (day == 0)
            break;

        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        strcpy(temp, day_str);
        strcat(temp, msg_str);

        /* Find insertion point */
        for (i = 0; i < num_remind; i++)
        {
            if (strcmp(temp, reminders[i]->str) < 0)
                break;
        }

        /* Shift pointers */
        for (j = num_remind; j > i; j--)
            reminders[j] = reminders[j - 1];

        /* Allocate the vstring structure */
        reminders[i] = malloc(sizeof(vstring));

        if (reminders[i] == NULL)
        {
            printf("-- No space left --\n");
            break;
        }

        reminders[i]->len = strlen(temp);

        /* Allocate memory for the string */
        reminders[i]->str = malloc(reminders[i]->len + 1);

        if (reminders[i]->str == NULL)
        {
            free(reminders[i]);
            printf("-- No space left --\n");
            break;
        }

        strcpy(reminders[i]->str, temp);

        num_remind++;
    }

    printf("\nDay Reminder\n");

    for (i = 0; i < num_remind; i++)
        printf("%s\n", reminders[i]->str);

    /* Free memory */
    for (i = 0; i < num_remind; i++)
    {
        free(reminders[i]->str);
        free(reminders[i]);
    }

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
