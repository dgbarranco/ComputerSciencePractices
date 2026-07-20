#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
    char walk[10][10];

    srand((unsigned)time(NULL));

    generate_random_walk(walk);
    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[10][10])
{
    int row, col, dir, i;

    for (row = 0; row < 10; row++)
        for (col = 0; col < 10; col++)
            walk[row][col] = '.';

    row = 0;
    col = 0;
    walk[row][col] = 'A';

    for (char ch = 'B'; ch <= 'Z'; ch++)
    {
        int tried[4] = {0};

        for (i = 0; i < 4; i++)
        {
            dir = rand() % 4;

            while (tried[dir])
                dir = rand() % 4;

            tried[dir] = 1;

            int newRow = row;
            int newCol = col;

            switch (dir)
            {
                case 0: newRow--; break;
                case 1: newCol++; break;
                case 2: newRow++; break;
                case 3: newCol--; break;
            }

            if (newRow >= 0 && newRow < 10 &&
                newCol >= 0 && newCol < 10 &&
                walk[newRow][newCol] == '.')
            {
                row = newRow;
                col = newCol;
                walk[row][col] = ch;
                break;
            }
        }

        if (i == 4)
            break;
    }
}

void print_array(char walk[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("%c ", walk[i][j]);

        printf("\n");
    }
}
