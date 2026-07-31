#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "readline.h"

int find_part(struct part inventory[], int num_parts, int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;

    return -1;
}

void insert(struct part **inventory,
            int *num_parts,
            int *max_parts)
{
    int part_number;
    struct part *temp;

    if (*num_parts == *max_parts)
    {
        *max_parts *= 2;

        temp = realloc(*inventory,
                       (*max_parts) * sizeof(struct part));

        if (temp == NULL)
        {
            printf("Unable to expand inventory.\n");
            exit(EXIT_FAILURE);
        }

        *inventory = temp;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(*inventory, *num_parts, part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    (*inventory)[*num_parts].number = part_number;

    printf("Enter part name: ");
    read_line((*inventory)[*num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &(*inventory)[*num_parts].on_hand);

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
        printf("Quantity on hand: %d\n",
               inventory[i].on_hand);
    }
    else
        printf("Part not found.\n");
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
        printf("Part not found.\n");
}

void print(struct part inventory[], int num_parts)
{
    int i;

    printf("\nPart Number   Part Name                  Quantity\n");
    printf("-------------------------------------------------\n");

    for (i = 0; i < num_parts; i++)
    {
        printf("%7d       %-25s %8d\n",
               inventory[i].number,
               inventory[i].name,
               inventory[i].on_hand);
    }
}
