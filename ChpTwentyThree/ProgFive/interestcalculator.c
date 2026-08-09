
#include <stdio.h>
#include <math.h>

int main(void)
{
  double P, r, t, A;

  printf("Enter the amount deposited: ");
  scanf("%lf", &P);

  printf("Enter the interest rate: ");
  scanf("%lf", &r);

  printf("Enter the number of years: ");
  scanf("%lf", &t);

  r = r / 100.0;

  A = P * exp(r * t);

  printf("Final value: $%.2f\n", A);

  return 0;
}
