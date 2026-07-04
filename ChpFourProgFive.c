#include <stdio.h>

int main(void)
{
    int id;
    int d1, d2, d3, d4, d5, d6;
    int check;

    printf("Enter a six-digit ID: ");
    scanf("%d", &id);

    d1 = id / 100000;
    d2 = (id / 10000) % 10;
    d3 = (id / 1000) % 10;
    d4 = (id / 100) % 10;
    d5 = (id / 10) % 10;
    d6 = id % 10;

    check = (d1 + d2 + d3 + d4 + d5 + d6) % 10;

    printf("Check digit: %d\n", check);

    return 0;
}
