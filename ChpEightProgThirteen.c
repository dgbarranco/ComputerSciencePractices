#include <stdio.h>

int main(void)
{
    char first[21];
    char last[21];

    printf("Enter first and last name: ");

    scanf("%20s %20s", first, last);

    printf("You entered the name: %s, %c.\n",
           last,
           first[0]);

    return 0;
}
