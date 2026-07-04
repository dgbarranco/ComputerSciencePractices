#include <stdio.h>

int main(void)
{
    int hour, minute;
    int total;

    printf("Enter a time (24-hour hh:mm): ");
    scanf("%d:%d", &hour, &minute);

    total = hour * 60 + minute;

    if (total < 480)
        printf("Closest departure: 8:00 AM\n");
    else if (total < 600)
        printf("Closest departure: 10:00 AM\n");
    else if (total < 720)
        printf("Closest departure: 12:00 PM\n");
    else if (total < 900)
        printf("Closest departure: 3:00 PM\n");
    else if (total < 1080)
        printf("Closest departure: 6:00 PM\n");
    else
        printf("Closest departure: 9:00 PM\n");

    return 0;
}
