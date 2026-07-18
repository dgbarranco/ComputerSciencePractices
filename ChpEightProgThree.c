#include <stdio.h>

int main(void)
{
    long n;

    while (1) {
        int occurrences[10] = {0};

        printf("Enter a number (0 or negative to quit): ");
        scanf("%ld", &n);

        if (n <= 0)
            break;

        long temp = n;

        while (temp > 0) {
            occurrences[temp % 10]++;
            temp /= 10;
        }

        printf("Digit:       ");

        for (int i = 0; i < 10; i++)
            printf("%d ", i);

        printf("\nOccurrences: ");

        for (int i = 0; i < 10; i++)
            printf("%d ", occurrences[i]);

        printf("\n\n");
    }

    printf("Program terminated.\n");

    return 0;
}
