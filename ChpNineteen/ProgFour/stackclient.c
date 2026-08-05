#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Stack s1, s2;
    char *str;

    s1 = create();
    s2 = create();

    push(s1, "One");
    printf("Length of s1 = %d\n", length(s1));

    push(s1, "Two");
    printf("Length of s1 = %d\n", length(s1));

    str = pop(s1);
    printf("Popped \"%s\" from s1\n", str);
    printf("Length of s1 = %d\n", length(s1));

    push(s2, str);
    printf("Length of s2 = %d\n", length(s2));

    str = pop(s1);
    printf("Popped \"%s\" from s1\n", str);
    printf("Length of s1 = %d\n", length(s1));

    push(s2, str);
    printf("Length of s2 = %d\n", length(s2));

    destroy(s1);

    while (!is_empty(s2))
    {
        str = pop(s2);
        printf("Popped \"%s\" from s2\n", str);
        printf("Length of s2 = %d\n", length(s2));
    }

    push(s2, "Three");
    printf("Length of s2 = %d\n", length(s2));

    make_empty(s2);

    if (is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}
