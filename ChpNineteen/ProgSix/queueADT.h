#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;

Queue create(int size);
void destroy(Queue q);

void make_empty(Queue q);

bool is_empty(Queue q);
bool is_full(Queue q);

void insert(Queue q, int item);
int remove_item(Queue q);

int first(Queue q);
int last(Queue q);

#endif
