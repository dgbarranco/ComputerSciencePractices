#include <stdio.h>

int main(void)
{
    int hour, minute;

    printf("Enter a 24-hour time (HH:MM): ");
    scanf("%d:%d", &hour, &minute);

    if (hour == 0)
        printf("Equivalent time: 12:%02d AM\n", minute);
    else if (hour < 12)
        printf("Equivalent time: %d:%02d AM\n", hour, minute);
    else if (hour == 12)
        printf("Equivalent time: 12:%02d PM\n", minute);
    else
        printf("Equivalent time: %d:%02d PM\n", hour - 12, minute);

    return 0;
}
