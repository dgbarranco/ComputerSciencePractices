#include <stdio.h>

struct dialing_code
{
    char *country;
    int code;
};

const struct dialing_code country_codes[] =
{
    {"Argentina", 54},
    {"Bangladesh", 880},
    {"Brazil", 55},
    {"Burma (Myanmar)", 95},
    {"China", 86},
    {"Colombia", 57},
    {"Congo, Dem. Rep. of", 243},
    {"Egypt", 20},
    {"Ethiopia", 251},
    {"France", 33},
    {"Germany", 49},
    {"India", 91},
    {"Indonesia", 62},
    {"Iran", 98},
    {"Italy", 39},
    {"Japan", 81},
    {"Mexico", 52},
    {"Nigeria", 234},
    {"Pakistan", 92},
    {"Philippines", 63},
    {"Poland", 48},
    {"Russia", 7},
    {"South Africa", 27},
    {"South Korea", 82},
    {"Spain", 34},
    {"Thailand", 66},
    {"Turkey", 90},
    {"United Kingdom", 44},
    {"United States", 1},
    {"Vietnam", 84}
};

int main(void)
{
    int code;
    int i;
    int found = 0;

    printf("Enter international dialing code: ");
    scanf("%d", &code);

    for (i = 0; i < sizeof(country_codes) / sizeof(country_codes[0]); i++)
    {
        if (country_codes[i].code == code)
        {
            printf("The country is %s\n", country_codes[i].country);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Error: Country code not found.\n");

    return 0;
}
