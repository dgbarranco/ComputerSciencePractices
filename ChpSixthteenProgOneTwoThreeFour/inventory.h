#ifndef INVENTORY_H
#define INVENTORY_H

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

extern struct part inventory[MAX_PARTS];
extern int num_parts;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

#endif
