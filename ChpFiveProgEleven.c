#include <stdio.h>

int main(void)
{
    int number;
    int tens, ones;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    tens = number / 10;
    ones = number % 10;

    if (tens == 1)
    {
        switch (ones)
        {
            case 0: printf("ten\n"); break;
            case 1: printf("eleven\n"); break;
            case 2: printf("twelve\n"); break;
            case 3: printf("thirteen\n"); break;
            case 4: printf("fourteen\n"); break;
            case 5: printf("fifteen\n"); break;
            case 6: printf("sixteen\n"); break;
            case 7: printf("seventeen\n"); break;
            case 8: printf("eighteen\n"); break;
            case 9: printf("nineteen\n"); break;
        }
    }
    else
    {
        switch (tens)
        {
            case 2: printf("twenty"); break;
            case 3: printf("thirty"); break;
            case 4: printf("forty"); break;
            case 5: printf("fifty"); break;
            case 6: printf("sixty"); break;
            case 7: printf("seventy"); break;
            case 8: printf("eighty"); break;
            case 9: printf("ninety"); break;
        }

        if (ones != 0)
        {
            printf("-");

            switch (ones)
            {
                case 1: printf("one"); break;
                case 2: printf("two"); break;
                case 3: printf("three"); break;
                case 4: printf("four"); break;
                case 5: printf("five"); break;
                case 6: printf("six"); break;
                case 7: printf("seven"); break;
                case 8: printf("eight"); break;
                case 9: printf("nine"); break;
            }
        }

        printf("\n");
    }

    return 0;
}
