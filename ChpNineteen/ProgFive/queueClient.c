#include <stdio.h>
#include "queueADT.h"

int main(void)
{
    Queue q1, q2;

    q1 = create();
    q2 = create();

    insert(q1, 10);
    insert(q1, 20);
    insert(q1, 30);

    printf("First item in q1: %d\n", first(q1));
    printf("Last item in q1: %d\n", last(q1));

    printf("Removed %d from q1\n", remove_item(q1));
    printf("Removed %d from q1\n", remove_item(q1));

    insert(q2, 100);
    insert(q2, 200);

    printf("First item in q2: %d\n", first(q2));
    printf("Last item in q2: %d\n", last(q2));

    printf("Removed %d from q2\n", remove_item(q2));

    make_empty(q1);

    if (is_empty(q1))
        printf("q1 is empty\n");
    else
        printf("q1 is not empty\n");

    destroy(q1);
    destroy(q2);

    return 0;
}
