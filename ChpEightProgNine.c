#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char grid[10][10];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            grid[i][j] = '.';

    srand((unsigned) time(NULL));

    int row = 0;
    int col = 0;

    grid[row][col] = 'A';

    for (char ch = 'B'; ch <= 'Z'; ch++) {

        int direction;
        int moved = 0;

        for (int tries = 0; tries < 4 && !moved; tries++) {

            direction = rand() % 4;

            int newRow = row;
            int newCol = col;

            switch (direction) {
                case 0: newRow--; break;
                case 1: newRow++; break;
                case 2: newCol--; break;
                case 3: newCol++; break;
            }

            if (newRow >= 0 &&
                newRow < 10 &&
                newCol >= 0 &&
                newCol < 10 &&
                grid[newRow][newCol] == '.') {

                row = newRow;
                col = newCol;
                grid[row][col] = ch;
                moved = 1;
            }
        }

        if (!moved)
            break;
    }

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++)
            printf("%c ", grid[i][j]);

        printf("\n");
    }

    return 0;
}
