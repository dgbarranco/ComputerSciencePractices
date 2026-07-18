#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char message[100];
    int i = 0;

    printf("Enter message: ");

    while ((message[i] = getchar()) != '\n' && i < 99)
        i++;

    message[i] = '\0';

    printf("In BIFF-speak: ");

    for (i = 0; message[i] != '\0'; i++) {

        char ch = toupper(message[i]);

        switch (ch) {
            case 'A': putchar('4'); break;
            case 'B': putchar('8'); break;
            case 'E': putchar('3'); break;
            case 'I': putchar('1'); break;
            case 'O': putchar('0'); break;
            case 'S': putchar('5'); break;
            default:
                putchar(ch);
        }
    }

    printf("!!!!!!!!!!\n");

    return 0;
}
