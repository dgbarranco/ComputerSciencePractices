#include <stdio.h>

int main(void)
{
    float loan;
    float interest;
    float payment;
    float monthly_rate;
    int payments;
    int i;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &interest);

    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    printf("Enter number of payments: ");
    scanf("%d", &payments);

    monthly_rate = interest / 100.0f / 12.0f;

    for (i = 1; i <= payments; i++)
    {
        loan = loan + loan * monthly_rate - payment;
        printf("Balance remaining after payment %d: $%.2f\n", i, loan);
    }

    return 0;
}
