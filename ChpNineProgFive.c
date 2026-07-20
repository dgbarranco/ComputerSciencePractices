#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
    int n;

    printf("Enter size of magic square (odd number): ");
    scanf("%d", &n);

    int magic_square[n][n];

    create_magic_square(n, magic_square);
    print_magic_square(n, magic_square);

    return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
    int row, col;

    for (row = 0; row < n; row++)
        for (col = 0; col < n; col++)
            magic_square[row][col] = 0;

    row = 0;
    col = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        magic_square[row][col] = num;

        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (magic_square[newRow][newCol] != 0)
            row = (row + 1) % n;
        else
        {
            row = newRow;
            col = newCol;
        }
    }
}

void print_magic_square(int n, int magic_square[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", magic_square[i][j]);

        printf("\n");
    }
}
