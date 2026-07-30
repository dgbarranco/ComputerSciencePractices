#include <stdio.h>
#include <stdlib.h>

struct flight
{
    int departure;
    int arrival;
};

int main(void)
{
    struct flight flights[] =
    {
        {480, 616},    /* 8:00 AM -> 10:16 AM */
        {583, 712},    /* 9:43 AM -> 11:52 AM */
        {679, 811},    /* 11:19 AM -> 1:31 PM */
        {767, 900},    /* 12:47 PM -> 3:00 PM */
        {840, 968},    /* 2:00 PM -> 4:08 PM */
        {945, 1075},   /* 3:45 PM -> 5:55 PM */
        {1140, 1280},  /* 7:00 PM -> 9:20 PM */
        {1305, 1438}   /* 9:45 PM -> 11:58 PM */
    };

    int hour, minute;
    int time;
    int i, closest = 0;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hour, &minute);

    time = hour * 60 + minute;

    for (i = 1; i < 8; i++)
    {
        if (abs(time - flights[i].departure) <
            abs(time - flights[closest].departure))
        {
            closest = i;
        }
    }

    printf("Closest departure time is %02d:%02d",
           flights[closest].departure / 60,
           flights[closest].departure % 60);

    printf(", arriving at %02d:%02d\n",
           flights[closest].arrival / 60,
           flights[closest].arrival % 60);

    return 0;
}
