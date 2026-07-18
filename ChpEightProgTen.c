#include <stdio.h>

int main(void)
{
    int departures[] = {
        480, 583, 679, 767,
        840, 945, 1140, 1305
    };

    int arrivals[] = {
        616, 712, 811, 900,
        968, 1075, 1280, 1438
    };

    int hour, minute;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hour, &minute);

    int userTime = hour * 60 + minute;

    int closest = 0;

    for (int i = 1; i < 8; i++) {

        if (abs(userTime - departures[i]) <
            abs(userTime - departures[closest]))
            closest = i;
    }

    printf("\nClosest departure is at %d:%02d\n",
           departures[closest] / 60,
           departures[closest] % 60);

    printf("Arrival time is %d:%02d\n",
           arrivals[closest] / 60,
           arrivals[closest] % 60);

    return 0;
}
