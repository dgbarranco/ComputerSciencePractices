#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date date1, date2;
    int result;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",
          &date1.month,
          &date1.day,
          &date1.year);

    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",
          &date2.month,
          &date2.day,
          &date2.year);

    result = compare_dates(date1, date2);

    if (result < 0)
        printf("First date is earlier.\n");
    else if (result > 0)
        printf("Second date is earlier.\n");
    else
        printf("The dates are the same.\n");

    return 0;
}

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;

    if (d1.month < d2.month)
        return -1;
    else if (d1.month > d2.month)
        return 1;

    if (d1.day < d2.day)
        return -1;
    else if (d1.day > d2.day)
        return 1;

    return 0;
}
