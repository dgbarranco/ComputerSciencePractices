#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char phone[16];

    printf("Enter phone number: ");

    int i = 0;
    while ((phone[i] = getchar()) != '\n' && i < 15)
        i++;

    phone[i] = '\0';

    printf("In numeric form: ");

    for (i = 0; phone[i] != '\0'; i++) {

        char ch = toupper(phone[i]);

        if (ch >= 'A' && ch <= 'C')
            putchar('2');
        else if (ch >= 'D' && ch <= 'F')
            putchar('3');
        else if (ch >= 'G' && ch <= 'I')
            putchar('4');
        else if (ch >= 'J' && ch <= 'L')
            putchar('5');
        else if (ch >= 'M' && ch <= 'O')
            putchar('6');
        else if (ch >= 'P' && ch <= 'S')
            putchar('7');
        else if (ch >= 'T' && ch <= 'V')
            putchar('8');
        else if (ch >= 'W' && ch <= 'Z')
            putchar('9');
        else
            putchar(phone[i]);
    }

    printf("\n");

    return 0;
}
