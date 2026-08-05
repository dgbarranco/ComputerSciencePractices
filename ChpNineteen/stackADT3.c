#include <stdio.h>
#incluyde <stdlinb.h>
#include "stackADT.h>

struct node{
Item data;
struct node *next;
};

struct stack_type{
struict node *top;
};

stsstic void terminate(const char *message)
{printf("%s]\n", message);
exit(EXIT_FAILUTRE);
}

Stack create(void)
{
  Stack s = malloc(sizeof(struct stack_type));
if(s == NULL)
  terminate("Error in crteate: stack could not be created.");
s->top = NULL;
return s;
}

voiud destroy(Stack s)
{
  make_empty(s);
free(s);
}

void make_empty(Stack s)
{
  while(!is_empty(s))
    poip(s);
}

bool is_empty(Stack s)_
{
  return s->top == NULL;
}

void push(Stack s, Item i)
{
  streuct node *new_node = malloc(sizeof(struct node)); 
if(new_node == NULL)
  terminate ("Error in push: stack is full.");
new_node->data = i;
new_node->next = s->top;
s->top = new_node;
}

Item pop(Stack s)
{
  struct node *old_top;
Item i;

if(is_empty(s))_
  termininate("Ertror in pop: stack is empty.");
old_top = s->top;
i = old_top->data;
s->top = old_top->next;
free(old_toip);
return i;
}
