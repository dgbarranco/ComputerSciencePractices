#include <stdio.h>
#include "queueADT.h"

int main(void)
{
    Queue q1, q2;

    q1 = create(5);
    q2 = create(10);

    insert(q1, 10);
    insert(q1, 20);
    insert(q1, 30);

    printf("First in q1: %d\n", first(q1));
    printf("Last in q1: %d\n", last(q1));

    printf("Removed %d\n", remove_item(q1));

    insert(q2, 100);
    insert(q2, 200);

    printf("First in q2: %d\n", first(q2));
    printf("Last in q2: %d\n", last(q2));

    destroy(q1);
    destroy(q2);

    return 0;
}
