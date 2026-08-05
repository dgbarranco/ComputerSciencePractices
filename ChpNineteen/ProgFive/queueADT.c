#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type
{
    int contents[QUEUE_SIZE];
    int front;
    int rear;
    int size;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));

    if (q == NULL)
        terminate("Error: Queue could not be created.");

    q->front = 0;
    q->rear = 0;
    q->size = 0;

    return q;
}

void destroy(Queue q)
{
    free(q);
}

void make_empty(Queue q)
{
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

bool is_empty(Queue q)
{
    return q->size == 0;
}

bool is_full(Queue q)
{
    return q->size == QUEUE_SIZE;
}

void insert(Queue q, int item)
{
    if (is_full(q))
        terminate("Error: Queue is full.");

    q->contents[q->rear] = item;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->size++;
}

int remove_item(Queue q)
{
    int item;

    if (is_empty(q))
        terminate("Error: Queue is empty.");

    item = q->contents[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->size--;

    return item;
}

int first(Queue q)
{
    if (is_empty(q))
        terminate("Error: Queue is empty.");

    return q->contents[q->front];
}

int last(Queue q)
{
    int index;

    if (is_empty(q))
        terminate("Error: Queue is empty.");

    index = (q->rear - 1 + QUEUE_SIZE) % QUEUE_SIZE;

    return q->contents[index];
}
