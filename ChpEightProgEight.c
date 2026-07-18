#include <stdio.h>

int main(void)
{
    int grades[5][5];

    for (int student = 0; student < 5; student++) {

        printf("Enter grades for student %d: ", student + 1);

        for (int quiz = 0; quiz < 5; quiz++)
            scanf("%d", &grades[student][quiz]);
    }

    printf("\nStudent Results\n");

    for (int student = 0; student < 5; student++) {

        int total = 0;

        for (int quiz = 0; quiz < 5; quiz++)
            total += grades[student][quiz];

        printf("Student %d: Total = %d Average = %.2f\n",
               student + 1,
               total,
               total / 5.0);
    }

    printf("\nQuiz Statistics\n");

    for (int quiz = 0; quiz < 5; quiz++) {

        int total = 0;
        int high = grades[0][quiz];
        int low = grades[0][quiz];

        for (int student = 0; student < 5; student++) {

            total += grades[student][quiz];

            if (grades[student][quiz] > high)
                high = grades[student][quiz];

            if (grades[student][quiz] < low)
                low = grades[student][quiz];
        }

        printf("Quiz %d: Average = %.2f High = %d Low = %d\n",
               quiz + 1,
               total / 5.0,
               high,
               low);
    }

    return 0;
}
