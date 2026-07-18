#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char message[81];
    int shift;

    printf("Enter message to be encrypted: ");

    int i = 0;

    while ((message[i] = getchar()) != '\n')
        i++;

    message[i] = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    printf("Encrypted message: ");

    for (i = 0; message[i] != '\0'; i++) {

        char ch = message[i];

        if (isupper(ch))
            ch = ((ch - 'A') + shift) % 26 + 'A';

        else if (islower(ch))
            ch = ((ch - 'a') + shift) % 26 + 'a';

        putchar(ch);
    }

    printf("\n");

    return 0;
}
