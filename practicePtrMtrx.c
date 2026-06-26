#include <stdio.h>

#define ROWS 5
#define COLS 20

int main() {

    char matrix[ROWS][COLS];
    char *ptr;

    for (int i = 0; i < ROWS; i++) {

        ptr = matrix[i];        // Pointer to the current row

        printf("Enter string %d: ", i + 1);
        scanf("%19s", ptr);     // Leave room for '\0'
    }

    printf("\nStrings entered:\n");

    for (int i = 0; i < ROWS; i++) {
        ptr = matrix[i];
        printf("%s\n", ptr);
    }

    return 0;
}
