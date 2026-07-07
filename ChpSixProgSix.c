#include <stdio.h>

int main(void)
{
    int n;
    int i;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 2; i * i <= n; i += 2)
    {
        printf("%d\n", i * i);
    }

    return 0;
}
