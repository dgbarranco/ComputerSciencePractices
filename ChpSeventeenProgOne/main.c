#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

int main(void)
{
    struct part *inventory;
    int num_parts = 0;
    int max_parts = 10;
    char code;

    inventory = malloc(max_parts * sizeof(struct part));

    if (inventory == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (;;)
    {
        printf("Enter operation code "
               "(i,s,u,p,q): ");

        scanf(" %c", &code);

        while (getchar() != '\n')
            ;

        switch (code)
        {
            case 'i':
                insert(&inventory, &num_parts, &max_parts);
                break;

            case 's':
                search(inventory, num_parts);
                break;

            case 'u':
                update(inventory, num_parts);
                break;

            case 'p':
                print(inventory, num_parts);
                break;

            case 'q':
                free(inventory);
                return 0;

            default:
                printf("Illegal code.\n");
        }

        printf("\n");
    }
}
