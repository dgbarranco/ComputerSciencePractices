#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 10

const int segments[10][7] = {
    {1,1,1,0,1,1,1}, //0
    {0,0,1,0,0,1,0}, //1
    {1,0,1,1,1,0,1}, //2
    {1,0,1,1,0,1,1}, //3
    {0,1,1,1,0,1,0}, //4
    {1,1,0,1,0,1,1}, //5
    {1,1,0,1,1,1,1}, //6
    {1,0,1,0,0,1,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}  //9
};

char display[3][MAX_DIGITS * 4];

void clear_display(void);
void process_digit(int digit, int position);
void print_display(void);

int main(void)
{
    char number[MAX_DIGITS + 1];

    printf("Enter a number (up to %d digits): ", MAX_DIGITS);
    scanf("%10s", number);

    clear_display();

    for (int i = 0; number[i] != '\0'; i++)
    {
        if (number[i] >= '0' && number[i] <= '9')
            process_digit(number[i] - '0', i);
    }

    print_display();

    return 0;
}

void clear_display(void)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < MAX_DIGITS * 4; col++)
            display[row][col] = ' ';
    }
}

void process_digit(int digit, int position)
{
    int col = position * 4;

    if (segments[digit][0]) display[0][col + 1] = '_';

    if (segments[digit][1]) display[1][col] = '|';
    if (segments[digit][2]) display[1][col + 2] = '|';
    if (segments[digit][3]) display[1][col + 1] = '_';

    if (segments[digit][4]) display[2][col] = '|';
    if (segments[digit][5]) display[2][col + 2] = '|';
    if (segments[digit][6]) display[2][col + 1] = '_';
}

void print_display(void)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < MAX_DIGITS * 4; col++)
            putchar(display[row][col]);

        putchar('\n');
    }
}
