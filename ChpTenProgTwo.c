#include <stdio.h>
#include <stdbool.h>

#define NUM_CARDS 5

int rank[NUM_CARDS];
char suit[NUM_CARDS];

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
    bool card_exists[4][13] = {false};

    int cards_read = 0;

    while (cards_read < NUM_CARDS)
    {
        char rank_ch, suit_ch;
        int r, s;

        printf("Enter a card: ");
        scanf(" %c%c", &rank_ch, &suit_ch);

        switch(rank_ch)
        {
            case '0': exit(0);
            case '2': r = 0; break;
            case '3': r = 1; break;
            case '4': r = 2; break;
            case '5': r = 3; break;
            case '6': r = 4; break;
            case '7': r = 5; break;
            case '8': r = 6; break;
            case '9': r = 7; break;
            case 't': case 'T': r = 8; break;
            case 'j': case 'J': r = 9; break;
            case 'q': case 'Q': r = 10; break;
            case 'k': case 'K': r = 11; break;
            case 'a': case 'A': r = 12; break;
            default:
                printf("Bad card.\n");
                while(getchar()!='\n');
                continue;
        }

        switch(suit_ch)
        {
            case 'c': case 'C': s = 0; break;
            case 'd': case 'D': s = 1; break;
            case 'h': case 'H': s = 2; break;
            case 's': case 'S': s = 3; break;
            default:
                printf("Bad suit.\n");
                while(getchar()!='\n');
                continue;
        }

        if(card_exists[s][r])
        {
            printf("Duplicate card.\n");
            continue;
        }

        card_exists[s][r] = true;

        rank[cards_read] = r;
        suit[cards_read] = suit_ch;

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

    for(int i=0;i<NUM_CARDS;i++)
    {
        rank_count[rank[i]]++;

        switch(suit[i])
        {
            case 'C': case 'c': suit_count[0]++; break;
            case 'D': case 'd': suit_count[1]++; break;
            case 'H': case 'h': suit_count[2]++; break;
            case 'S': case 's': suit_count[3]++; break;
        }
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
        {
            if(i>=13 || rank_count[i]==0)
            {
                straight=false;
                break;
            }
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
}

void print_result(void)
{
    if(straight && flush)
        printf("Straight flush");
    else if(four)
        printf("Four of a kind");
    else if(three && pairs==1)
        printf("Full house");
    else if(flush)
        printf("Flush");
    else if(straight)
        printf("Straight");
    else if(three)
        printf("Three of a kind");
    else if(pairs==2)
        printf("Two pairs");
    else if(pairs==1)
        printf("Pair");
    else
        printf("High card");
}
