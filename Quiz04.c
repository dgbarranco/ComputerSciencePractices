#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* Check for correct number of command-line arguments */
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    /* Convert N and validate it */
    char *endptr;
    long N = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0') {
        printf("Error: N must be an integer.\n");
        return 1;
    }

    if (N <= 0) {
        printf("Error: N must be greater than 0.\n");
        return 1;
    }

    int num;
    int logicalAnd;
    int bitwiseAnd;

    /* Read first integer */
    if (scanf("%d", &num) != 1) {
        printf("Error: Expected an integer.\n");
        return 1;
    }

    logicalAnd = num;
    bitwiseAnd = num;

    /* Read remaining N - 1 integers */
    for (long i = 1; i < N; i++) {
        if (scanf("%d", &num) != 1) {
            printf("Error: Expected %ld integers.\n", N);
            return 1;
        }

        logicalAnd = logicalAnd && num;
        bitwiseAnd = bitwiseAnd & num;
    }

    printf("Logical AND: %d\n", logicalAnd);
    printf("Bitwise AND: %d\n", bitwiseAnd);

    return 0;

}
