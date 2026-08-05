#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node
{
    int data;
    struct node *next;
};

struct queue_type
{
    struct node *front;
    struct node *rear;
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

    q->front = NULL;
    q->rear = NULL;

    return q;
}

void destroy(Queue q)
{
    make_empty(q);
    free(q);
}

void make_empty(Queue q)
{
    while (!is_empty(q))
        remove_item(q);
}

bool is_empty(Queue q)
{
    return q->front == NULL;
}

bool is_full(Queue q)
{
    return false;
}

void insert(Queue q, int item)
{
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
        terminate("Error: Queue is full.");

    new_node->data = item;
    new_node->next = NULL;

    if (is_empty(q))
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int remove_item(Queue q)
{
    struct node *old_front;
    int item;

    if (is_empty(q))
        terminate("Error: Queue is empty.");

    old_front = q->front;
    item = old_front->data;

    q->front = old_front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(old_front);

    return item;
}

int first(Queue q)
{
    if (is_empty(q))
        terminate("Error: Queue is empty.");

    return q->front->data;
}

int last(Queue q)
{
    if (is_empty(q))
        terminate("Error: Queue is empty.");

    return q->rear->data;
}
