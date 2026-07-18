#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int digit_seen[10] = {0};
    int repeated[10] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        int digit = n % 10;

        if (digit_seen[digit])
            repeated[digit] = 1;
        else
            digit_seen[digit] = 1;

        n /= 10;
    }

    printf("Repeated digit(s): ");

    bool found = false;

    for (int i = 0; i < 10; i++) {
        if (repeated[i]) {
            printf("%d ", i);
            found = true;
        }
    }

    if (!found)
        printf("None");

    printf("\n");

    return 0;
}
