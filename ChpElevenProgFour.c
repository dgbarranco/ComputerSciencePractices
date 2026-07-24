#include <stdio.h>
#include <stdbool.h>

void analyze_hand(int hand[], int size,
                  bool *pair,
                  bool *three,
                  bool *four)
{
    int count[13] = {0};

    // Count occurrences of each card rank (1-13)
    for (int i = 0; i < size; i++)
        count[hand[i] - 1]++;

    *pair = false;
    *three = false;
    *four = false;

    for (int i = 0; i < 13; i++)
    {
        if (count[i] == 2)
            *pair = true;
        else if (count[i] == 3)
            *three = true;
        else if (count[i] == 4)
            *four = true;
    }
}

int main(void)
{
    int hand[5];
    bool pair, three, four;

    printf("Enter 5 card ranks (1-13):\n");

    for (int i = 0; i < 5; i++)
        scanf("%d", &hand[i]);

    analyze_hand(hand, 5, &pair, &three, &four);

    printf("\nResults:\n");

    if (four)
        printf("Four of a Kind\n");
    else if (three)
        printf("Three of a Kind\n");
    else if (pair)
        printf("One Pair\n");
    else
        printf("High Card\n");

    return 0;
}
