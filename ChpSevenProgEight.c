#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, minute;
    char ampm;

    printf("Enter a 12-hour time: ");

    scanf("%d:%d %c",
          &hour,
          &minute,
          &ampm);

    ampm = toupper(ampm);

    printf("You entered %02d:%02d %cM\n",
           hour,
           minute,
           ampm);

    return 0;
}
