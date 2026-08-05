#include <stdio.h>
#include <stddef.h>   // for offsetof

struct example {
    char a;
    int b;
    char c;
};

int main(void)
{
    printf("Size of structure: %zu bytes\n\n", sizeof(struct example));

    printf("Member offsets:\n");
    printf("a: %zu bytes\n", offsetof(struct example, a));
    printf("b: %zu bytes\n", offsetof(struct example, b));
    printf("c: %zu bytes\n", offsetof(struct example, c));

    return 0;
}
