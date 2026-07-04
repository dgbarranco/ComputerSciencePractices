#include <stdio.h>

int main(void)
{
    int speed;

    printf("Enter wind speed: ");
    scanf("%d", &speed);

    if (speed < 1)
        printf("Category: Calm\n");
    else if (speed <= 15)
        printf("Category: Light Breeze\n");
    else if (speed <= 30)
        printf("Category: Moderate Wind\n");
    else if (speed <= 50)
        printf("Category: Strong Wind\n");
    else
        printf("Category: Severe Wind\n");

    return 0;
}
