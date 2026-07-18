#include <stdio.h>

int main(void)
{
    int a[] = {34, 82, 49, 102, 7, 94, 23};
    int length = sizeof(a) / sizeof(a[0]);

    printf("Reversed array:\n");

    for (int i = length - 1; i >= 0; i--)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
