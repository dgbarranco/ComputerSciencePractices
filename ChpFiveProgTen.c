#include <stdio.h>

int main(void)
{
    int grade;

    printf("Enter a numerical grade (0-100): ");
    scanf("%d", &grade);

    switch (grade / 10)
    {
        case 10:
        case 9:
            printf("Letter grade: A\n");
            break;

        case 8:
            printf("Letter grade: B\n");
            break;

        case 7:
            printf("Letter grade: C\n");
            break;

        case 6:
            printf("Letter grade: D\n");
            break;

        default:
            printf("Letter grade: F\n");
    }

    return 0;
}
