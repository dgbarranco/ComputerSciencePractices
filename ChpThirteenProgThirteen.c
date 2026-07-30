#include <stdio.h>

void encrypt(char *message, int shift);

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

    encrypt(message, shift);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    while (*message != '\0')
    {
        if (*message >= 'A' && *message <= 'Z')
        {
            *message = ((*message - 'A' + shift) % 26) + 'A';
        }
        else if (*message >= 'a' && *message <= 'z')
        {
            *message = ((*message - 'a' + shift) % 26) + 'a';
        }

        message++;
    }
}
