#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    char *endptr;
    long N = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || N <= 0) {
        printf("Error: N must be a positive integer.\n");
        return 1;
    }

    int logicalAnd;
    int bitwiseAnd;
    int count = 0;

    char buffer[100];

    while (count < N) {
        printf("Enter integer %d: ", count + 1);

        fgets(buffer, sizeof(buffer), stdin);

        long num = strtol(buffer, &endptr, 10);

        /* Validate input */
        if (*endptr != '\n' && *endptr != '\0') {
            printf("Invalid integer. Try again.\n");
            continue;
        }

        if (count == 0) {
            logicalAnd = num;
            bitwiseAnd = num;
        } else {
            logicalAnd = logicalAnd && num;
            bitwiseAnd = bitwiseAnd & num;
        }

        count++;
    }

    printf("Logical AND: %d\n", logicalAnd);
    printf("Bitwise AND: %d\n", bitwiseAnd);

    return 0;
}
