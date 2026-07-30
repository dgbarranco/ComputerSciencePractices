#include <stdio.h>
#include <string.h>
#include "inventory.h"
#include "readline.h"

int find_part(struct part inventory[], int num_parts, int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
    {
        if (inventory[i].number == number)
            return i;
    }

    return -1;
}

void insert(struct part inventory[], int *num_parts)
{
    int part_number;

    if (*num_parts == MAX_PARTS)
    {
        printf("Database is full.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(inventory, *num_parts, part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;

    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);

    printf("Enter price: ");
    scanf("%lf", &inventory[*num_parts].price);

    (*num_parts)++;
}

void search(struct part inventory[], int num_parts)
{
    int number, i;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);

    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: $%.2f\n", inventory[i].price);
    }
    else
    {
        printf("Part not found.\n");
    }
}

void update(struct part inventory[], int num_parts)
{
    int number, change, i;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);

    if (i >= 0)
    {
        printf("Enter change in quantity: ");
        scanf("%d", &change);

        inventory[i].on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

void change_price(struct part inventory[], int num_parts)
{
    int number, i;
    double new_price;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);

    if (i >= 0)
    {
        printf("Current price: $%.2f\n", inventory[i].price);

        printf("Enter new price: ");
        scanf("%lf", &new_price);

        inventory[i].price = new_price;
    }
    else
    {
        printf("Part not found.\n");
    }
}

void print(struct part inventory[], int num_parts)
{
    int i;

    printf("\nPart Number   Part Name                  Quantity   Price\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < num_parts; i++)
    {
        printf("%7d       %-25s %8d   $%8.2f\n",
               inventory[i].number,
               inventory[i].name,
               inventory[i].on_hand,
               inventory[i].price);
    }
}
