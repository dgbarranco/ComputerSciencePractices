#include <stdio.h>

int main(void)
{
    char message[81];
    int shift, i = 0;

    printf("Enter message to be encrypted: ");
    while ((message[i] = getchar()) != '\n' && i < 80)
    {
        i++;
    }
    message[i] = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    printf("Encrypted message: ");

    for (i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            printf("%c", ((message[i] - 'A' + shift) % 26) + 'A');
        }
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            printf("%c", ((message[i] - 'a' + shift) % 26) + 'a');
        }
        else
        {
            printf("%c", message[i]);
        }
    }

    printf("\n");

    return 0;
}
