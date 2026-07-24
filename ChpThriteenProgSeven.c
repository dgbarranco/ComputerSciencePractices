#include <stdio.h>

int main(void)
{
    int number;
    int tens, ones;

    char *ones_words[] = {
        "", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    char *teen_words[] = {
        "ten", "eleven", "twelve", "thirteen",
        "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };

    char *tens_words[] = {
        "", "", "twenty", "thirty",
        "forty", "fifty", "sixty",
        "seventy", "eighty", "ninety"
    };

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    tens = number / 10;
    ones = number % 10;

    if (tens == 1)
    {
        printf("%s\n", teen_words[ones]);
    }
    else
    {
        printf("%s", tens_words[tens]);

        if (ones != 0)
        {
            printf("-%s", ones_words[ones]);
        }

        printf("\n");
    }

    return 0;
}
