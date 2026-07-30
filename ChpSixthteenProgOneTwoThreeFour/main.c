#include <stdio.h>
#include "inventory.h"

int main(void)
{
    struct part inventory[MAX_PARTS];
    int num_parts = 0;
    char code;

    for (;;)
    {
        printf("Enter operation code ");
        printf("(i=insert, s=search, u=update, c=change price, p=print, q=quit): ");

        scanf(" %c", &code);

        while (getchar() != '\n')
            ;

        switch (code)
        {
            case 'i':
                insert(inventory, &num_parts);
                break;

            case 's':
                search(inventory, num_parts);
                break;

            case 'u':
                update(inventory, num_parts);
                break;

            case 'c':
                change_price(inventory, num_parts);
                break;

            case 'p':
                print(inventory, num_parts);
                break;

            case 'q':
                return 0;

            default:
                printf("Illegal code.\n");
        }

        printf("\n");
    }
}
