#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 12];
    char date_time[12];
    char msg_str[MSG_LEN + 1];

    int month, day;
    int hour, minute;
    int i, j;
    int num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No more reminders can be stored --\n");
            break;
        }

        printf("Enter date (month/day), time (hh:mm), and reminder: ");

        scanf("%d/%d %d:%d",
              &month,
              &day,
              &hour,
              &minute);

        if (month == 0)
            break;

        read_line(msg_str, MSG_LEN);

        /* Check valid date and time */
        if (month < 1 || month > 12 ||
            day < 1 || day > 31 ||
            hour < 0 || hour > 23 ||
            minute < 0 || minute > 59)
        {
            printf("Error: Invalid date or time. Reminder ignored.\n");
            continue;
        }

        /* Store date and time in sortable format */
        sprintf(date_time, "%02d/%02d %02d:%02d ",
                month, day, hour, minute);

        /* Find insertion location */
        for (i = 0; i < num_remind; i++)
        {
            if (strcmp(date_time, reminders[i]) < 0)
                break;
        }

        /* Shift reminders down */
        for (j = num_remind; j > i; j--)
        {
            strcpy(reminders[j], reminders[j - 1]);
        }

        /* Insert reminder */
        strcpy(reminders[i], date_time);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nReminder List\n");

    for (i = 0; i < num_remind; i++)
        printf("%s\n", reminders[i]);

    return 0;
}


int read_line(char str[], int n)
{
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n)
            str[i++] = ch;
    }

    str[i] = '\0';

    return i;
}
