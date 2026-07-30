#ifndef INVENTORY_H
#define INVENTORY_H

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

int find_part(struct part inventory[], int num_parts, int number);

void insert(struct part inventory[], int *num_parts);

void search(struct part inventory[], int num_parts);

void update(struct part inventory[], int num_parts);

void change_price(struct part inventory[], int num_parts);

void print(struct part inventory[], int num_parts);

#endif
