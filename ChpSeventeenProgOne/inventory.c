//Includes One and Two
#include <stdio.h>
#include <stdlib.h>
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
        printf("Database is full; can't add more parts.\n");
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

    (*num_parts)++;
}

void search(struct part inventory[], int num_parts)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);

    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
    {
        printf("Part not found.\n");
    }
}

void update(struct part inventory[], int num_parts)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);

    if (i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);

        inventory[i].on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

/* Comparison function used by qsort */
int compare_parts(const void *p, const void *q)
{
    const struct part *part1 = (const struct part *)p;
    const struct part *part2 = (const struct part *)q;

    if (part1->number < part2->number)
        return -1;
    else if (part1->number > part2->number)
        return 1;
    else
        return 0;
}

void print(struct part inventory[], int num_parts)
{
    int i;

    /* Sort inventory by part number */
    qsort(inventory,
          num_parts,
          sizeof(struct part),
          compare_parts);

    printf("\nPart Number   Part Name                  Quantity on Hand\n");
    printf("---------------------------------------------------------\n");

    for (i = 0; i < num_parts; i++)
    {
        printf("%7d       %-25s %8d\n",
               inventory[i].number,
               inventory[i].name,
               inventory[i].on_hand);
    }
}
