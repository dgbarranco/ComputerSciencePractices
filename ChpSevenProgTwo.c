#include <stdio.h>

int main(void)
{
    int i, count = 0;

    for (i = 1;; i++) {
        printf("%10d%10d\n", i, i * i);

        count++;

        if (count == 24) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');
            count = 0;
        }
    }

    return 0;
}
