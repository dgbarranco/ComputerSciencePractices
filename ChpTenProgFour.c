#include <stdio.h>
#include <stdbool.h>

#define NUM_CARDS 5

int card[NUM_CARDS][2];

bool royal_flush;
bool straight;
bool flush;
bool four;
bool three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    while (1)
    {
        read_cards();
        analyze_hand();
        print_result();
        printf("\n");
    }
}

void read_cards(void)
{
    bool exists[4][13] = {false};
    int cards_read = 0;

    while (cards_read < NUM_CARDS)
    {
        char r, s;
        int rank, suit;

        printf("Enter a card: ");
        scanf(" %c%c", &r, &s);

        switch(r)
        {
            case '2': rank=0; break;
            case '3': rank=1; break;
            case '4': rank=2; break;
            case '5': rank=3; break;
            case '6': rank=4; break;
            case '7': rank=5; break;
            case '8': rank=6; break;
            case '9': rank=7; break;
            case 'T': case 't': rank=8; break;
            case 'J': case 'j': rank=9; break;
            case 'Q': case 'q': rank=10; break;
            case 'K': case 'k': rank=11; break;
            case 'A': case 'a': rank=12; break;
            default:
                printf("Bad rank\n");
                continue;
        }

        switch(s)
        {
            case 'C': case 'c': suit=0; break;
            case 'D': case 'd': suit=1; break;
            case 'H': case 'h': suit=2; break;
            case 'S': case 's': suit=3; break;
            default:
                printf("Bad suit\n");
                continue;
        }

        if(exists[suit][rank])
        {
            printf("Duplicate card\n");
            continue;
        }

        exists[suit][rank]=true;

        card[cards_read][0]=rank;
        card[cards_read][1]=suit;

        cards_read++;
    }
}

void analyze_hand(void)
{
    int rank_count[13]={0};
    int suit_count[4]={0};

    straight=true;
    flush=false;
   four=false;
    three=false;
    pairs=0;
    royal_flush=false;

    for(int i=0;i<NUM_CARDS;i++)
    {
        rank_count[card[i][0]]++;
        suit_count[card[i][1]]++;
    }

    for(int i=0;i<4;i++)
        if(suit_count[i]==5)
            flush=true;

    int first=-1;

    for(int i=0;i<13;i++)
        if(rank_count[i])
        {
            first=i;
            break;
        }

    if(first==-1)
        straight=false;
    else
    {
        for(int i=first;i<first+5;i++)
            if(i>=13 || rank_count[i]==0)
            {
                straight=false;
                break;
            }
    }

    for(int i=0;i<13;i++)
    {
        if(rank_count[i]==4)
            four=true;
        else if(rank_count[i]==3)
            three=true;
        else if(rank_count[i]==2)
            pairs++;
    }

    if(flush &&
       rank_count[8] &&
       rank_count[9] &&
       rank_count[10] &&
       rank_count[11] &&
       rank_count[12])
    {
        royal_flush=true;
    }
}

void print_result(void)
{
    if(royal_flush)
        printf("Royal Flush");
    else if(straight && flush)
        printf("Straight Flush");
    else if(four)
        printf("Four of a Kind");
    else if(three && pairs==1)
        printf("Full House");
    else if(flush)
        printf("Flush");
    else if(straight)
        printf("Straight");
    else if(three)
        printf("Three of a Kind");
    else if(pairs==2)
        printf("Two Pairs");
    else if(pairs==1)
        printf("One Pair");
    else
        printf("High Card");
}
