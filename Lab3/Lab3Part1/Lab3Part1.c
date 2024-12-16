#include <math.h>
#include <stdio.h>

int main() {
  double a, b, c, x1, x2;
  printf("Please enter a, b, c: ");
  scanf("%lf %lf %lf", &a, &b, &c);
  double discriminant = (pow(b, 2) - (4 * a * c));
  if (discriminant > 0) {
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("The roots are real and distinct.\n");
    printf("Root 1: %0.2f\n", x1);
    printf("Root 2: %0.2f\n", x2);
  } else if (discriminant == 0 && (a > 0 || b > 0 || c > 0)) {
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    printf("The roots are real and equal.\n");
    printf("The Root: %0.2f\n", x1);
  } else {
    printf("No real roots exist.\n");
  }
  return 0;
}