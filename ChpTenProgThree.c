#include <stdio.h>
#include <stdbool.h>

#define NUM_CARDS 5

/* card[i][0] = rank
   card[i][1] = suit */
int card[NUM_CARDS][2];

bool straight, flush, four, three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    for (;;)
    {
        read_cards();
        analyze_hand();
        print_result();
        printf("\n");
    }

    return 0;
}

void read_cards(void)
{
    bool exists[4][13] = {false};
    int cards_read = 0;

    while (cards_read < NUM_CARDS)
    {
        char rank_ch, suit_ch;
        int rank, suit;

        printf("Enter a card: ");
        scanf(" %c%c", &rank_ch, &suit_ch);

        switch(rank_ch)
        {
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 'T': case 't': rank = 8; break;
            case 'J': case 'j': rank = 9; break;
            case 'Q': case 'q': rank = 10; break;
            case 'K': case 'k': rank = 11; break;
            case 'A': case 'a': rank = 12; break;
            default:
                printf("Bad card.\n");
                while(getchar()!='\n');
                continue;
        }

        switch(suit_ch)
        {
            case 'C': case 'c': suit = 0; break;
            case 'D': case 'd': suit = 1; break;
            case 'H': case 'h': suit = 2; break;
            case 'S': case 's': suit = 3; break;
            default:
                printf("Bad suit.\n");
                while(getchar()!='\n');
                continue;
        }

        if (exists[suit][rank])
        {
            printf("Duplicate card.\n");
            continue;
        }

        exists[suit][rank] = true;

        card[cards_read][0] = rank;
        card[cards_read][1] = suit;

        cards_read++;
    }
}

void analyze_hand(void)
{
    int rank_count[13] = {0};
    int suit_count[4] = {0};

    straight = true;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    for (int i = 0; i < NUM_CARDS; i++)
    {
        rank_count[card[i][0]]++;
        suit_count[card[i][1]]++;
    }

    for (int i = 0; i < 4; i++)
        if (suit_count[i] == 5)
            flush = true;

    int first = -1;

    for (int i = 0; i < 13; i++)
    {
        if (rank_count[i] > 0)
        {
            first = i;
            break;
        }
    }

    if (first == -1)
        straight = false;
    else
    {
        for (int i = first; i < first + 5; i++)
        {
            if (i >= 13 || rank_count[i] == 0)
            {
                straight = false;
                break;
            }
        }
    }

    for (int i = 0; i < 13; i++)
    {
        if (rank_count[i] == 4)
            four = true;
        else if (rank_count[i] == 3)
            three = true;
        else if (rank_count[i] == 2)
            pairs++;
    }
}

void print_result(void)
{
    if (straight && flush)
        printf("Straight Flush");
    else if (four)
        printf("Four of a Kind");
    else if (three && pairs == 1)
        printf("Full House");
    else if (flush)
        printf("Flush");
    else if (straight)
        printf("Straight");
    else if (three)
        printf("Three of a Kind");
    else if (pairs == 2)
        printf("Two Pairs");
    else if (pairs == 1)
        printf("One Pair");
    else
        printf("High Card");
}
