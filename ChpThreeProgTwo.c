#include <stdio.h>

int main(void)
{
    int itemNumber;
    float unitPrice;
    int month, day, year;

    printf("Enter item number: ");
    scanf("%d", &itemNumber);

    printf("Enter unit price: ");
    scanf("%f", &unitPrice);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("\n");
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");

    printf("%-8d\t$%7.2f\t%02d/%02d/%04d\n",
           itemNumber,
           unitPrice,
           month,
           day,
           year);

    return 0;
}
