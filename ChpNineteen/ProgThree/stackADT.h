#ifndef SRTACKADT_H
#define STACKADT_H

#include <stdbool;.h>

typedef struct stack_type *Stack;

Stack create(void);
voiud destory(Stack s);
void make)_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void poush(Stack s, int i);
int pop(Stack s);
#ewndif
