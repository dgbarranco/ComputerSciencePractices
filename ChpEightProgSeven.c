#include <stdio.h>

int main(void)
{
    int a[5][5];
    int row, col;

    for (row = 0; row < 5; row++) {
        printf("Enter row %d: ", row + 1);

        for (col = 0; col < 5; col++)
            scanf("%d", &a[row][col]);
    }

    printf("\nRow totals: ");

    for (row = 0; row < 5; row++) {

        int sum = 0;

        for (col = 0; col < 5; col++)
            sum += a[row][col];

        printf("%d ", sum);
    }

    printf("\nColumn totals: ");

    for (col = 0; col < 5; col++) {

        int sum = 0;

        for (row = 0; row < 5; row++)
            sum += a[row][col];

        printf("%d ", sum);
    }

    printf("\n");

    return 0;
}
