#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 9];
    char datetime_str[9];
    char msg_str[MSG_LEN + 1];
    int day, hour, minute;
    int i, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day, time (hh:mm), and reminder: ");
        scanf("%2d", &day);

        if (day == 0)
            break;

        scanf("%2d:%2d", &hour, &minute);
        read_line(msg_str, MSG_LEN);

        /* Check for invalid day or time */
        if (day < 1 || day > 31 ||
            hour < 0 || hour > 23 ||
            minute < 0 || minute > 59)
        {
            printf("Error: Invalid day or time. Reminder ignored.\n");
            continue;
        }

        /* Build string used for sorting */
        sprintf(datetime_str, "%02d %02d:%02d ", day, hour, minute);

        /* Find where the reminder belongs */
        for (i = 0; i < num_remind; i++)
            if (strcmp(datetime_str, reminders[i]) < 0)
                break;

        /* Move reminders down one position */
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);

        /* Insert the new reminder */
        strcpy(reminders[i], datetime_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Time  Reminder\n");

    for (i = 0; i < num_remind; i++)
        printf("%s\n", reminders[i]);

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
