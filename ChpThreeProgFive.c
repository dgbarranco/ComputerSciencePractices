#include <stdio.h>

int main(void)
{
    int square[4][4];
    int rowSum, colSum;
    int diag1 = 0;
    int diag2 = 0;

    printf("Enter the numbers from 1 to 16 in any order:\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &square[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%4d", square[i][j]);
        }
        printf("\n");
    }

    printf("\nRow sums:");

    for (int i = 0; i < 4; i++)
    {
        rowSum = 0;

        for (int j = 0; j < 4; j++)
        {
            rowSum += square[i][j];
        }

        printf("%4d", rowSum);
    }

    printf("\nColumn sums:");

    for (int j = 0; j < 4; j++)
    {
        colSum = 0;

        for (int i = 0; i < 4; i++)
        {
            colSum += square[i][j];
        }

        printf("%4d", colSum);
    }

    for (int i = 0; i < 4; i++)
    {
        diag1 += square[i][i];
        diag2 += square[i][3 - i];
    }

    printf("\nDiagonal sums:%4d%4d\n", diag1, diag2);

    return 0;
}
