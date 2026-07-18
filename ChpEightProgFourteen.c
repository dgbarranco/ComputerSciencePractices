#include <stdio.h>

int main(void)
{
    char sentence[200];
    char end;
    int i = 0;

    printf("Enter a sentence: ");

    while (1) {
        scanf("%c", &sentence[i]);

        if (sentence[i] == '.' ||
            sentence[i] == '?' ||
            sentence[i] == '!') {

            end = sentence[i];
            break;
        }

        i++;
    }

    int last = i;

    printf("Reversal of sentence: ");

    while (last >= 0) {

        while (last >= 0 && sentence[last] != ' ')
            last--;

        int start = last + 1;

        while (sentence[start] != ' ' && start < i) {
            printf("%c", sentence[start]);
            start++;
        }

        if (last > 0)
            printf(" ");

        last--;
    }

    printf("%c\n", end);

    return 0;
}
