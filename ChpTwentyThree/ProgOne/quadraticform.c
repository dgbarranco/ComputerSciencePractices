
#include <stdio.h>
#include <math.h>

int main(void)
{
  double a, b, c;
  double discriminant;
  double x1, x2;

  printf("Enter a, b, and c: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  discriminant = b * b - 4 * a * c;

  if (discriminant < 0) {
    printf("The roots are complex.\n");
  } else {
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);

    printf("x1 = %.2f\n", x1);
    printf("x2 = %.2f\n", x2);
  }

  return 0;
}

