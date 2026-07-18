#include <stdio.h>

int main(void)
{
    int occurrences[10] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        occurrences[n % 10]++;
        n /= 10;
    }

    printf("\nDigit:       ");

    for (int i = 0; i < 10; i++)
        printf("%d ", i);

    printf("\nOccurrences: ");

    for (int i = 0; i < 10; i++)
        printf("%d ", occurrences[i]);

    printf("\n");

    return 0;
}
