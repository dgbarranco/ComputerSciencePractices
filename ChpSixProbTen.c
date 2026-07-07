#include <stdio.h>

int main(void)
{
    int month, day, year;
    int earliest_month, earliest_day, earliest_year;
    int first_date = 1;

    while (1)
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &day, &year);

        if (month == 0 && day == 0 && year == 0)
            break;

        if (first_date)
        {
            earliest_month = month;
            earliest_day = day;
            earliest_year = year;
            first_date = 0;
        }
        else if (year < earliest_year ||
                (year == earliest_year && month < earliest_month) ||
                (year == earliest_year && month == earliest_month &&
                 day < earliest_day))
        {
            earliest_month = month;
            earliest_day = day;
            earliest_year = year;
        }
    }

    printf("%d/%d/%02d is the earliest date\n",
           earliest_month,
           earliest_day,
           earliest_year);

    return 0;
}
