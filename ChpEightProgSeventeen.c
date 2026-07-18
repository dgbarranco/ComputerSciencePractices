#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter size of magic square (odd 1-99): ");
    scanf("%d", &n);

    int square[99][99] = {0};

    int row = 0;
    int col = n / 2;

    for (int num = 1; num <= n * n; num++) {

        square[row][col] = num;

        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (square[newRow][newCol] != 0)
            row = (row + 1) % n;
        else {
            row = newRow;
            col = newCol;
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++)
            printf("%4d", square[i][j]);

        printf("\n");
    }

    return 0;
}
