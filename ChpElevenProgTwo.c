#include <stdio.h>

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time);

int main(void)
{
    int hour, minute;
    int desired;
    int departure, arrival;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hour, &minute);

    desired = hour * 60 + minute;

    find_closest_flight(desired, &departure, &arrival);

    printf("Departure: %02d:%02d\n",
           departure / 60, departure % 60);

    printf("Arrival: %02d:%02d\n",
           arrival / 60, arrival % 60);

    return 0;
}

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time)
{
    int departures[] = {
        480, 583, 679, 767,
        840, 945, 1140, 1305
    };

    int arrivals[] = {
        616, 712, 811, 900,
        968, 1075, 1280, 1438
    };

    int i, closest = 0;

    for (i = 1; i < 8; i++)
    {
        if (desired_time < (departures[i - 1] + departures[i]) / 2)
        {
            closest = i - 1;
            break;
        }
        closest = i;
    }

    *departure_time = departures[closest];
    *arrival_time = arrivals[closest];
}
