#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    char answer;
    int wins = 0;
    int losses = 0;

    srand((unsigned) time(NULL));

    while (1)
    {
        if (play_game())
            wins++;
        else
            losses++;

        printf("\nPlay again? ");
        scanf(" %c", &answer);

        if (answer != 'y' && answer != 'Y')
            break;
    }

    printf("\nWins: %d   Losses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void)
{
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

bool play_game(void)
{
    int roll = roll_dice();

    printf("You rolled: %d\n", roll);

    switch (roll)
    {
        case 7:
        case 11:
            printf("You win!\n");
            return true;

        case 2:
        case 3:
        case 12:
            printf("You lose!\n");
            return false;

        default:
        {
            int point = roll;

            printf("Your point is %d\n", point);

            while (1)
            {
                roll = roll_dice();

                printf("You rolled: %d\n", roll);

                if (roll == point)
                {
                    printf("You win!\n");
                    return true;
                }

                if (roll == 7)
                {
                    printf("You lose!\n");
                    return false;
                }
            }
        }
    }
}
