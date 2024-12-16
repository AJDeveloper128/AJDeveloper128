#include <math.h>
#include <stdio.h>

int main() {
  double x, y;
  printf("Enter the x-coordinate in floating point: ");
  scanf("%lf", &x);
  printf("Enter the y-coordinate in floating point: ");
  scanf("%lf", &y);
  x = round(x * 100) / 100;
  y = round(y * 100) / 100;
  if (x == 0.00 && y == 0.00) {
    printf("(%0.2lf, %0.2lf) is at the origin.\n", x, y);
  } else if (x == 0.00) {
    printf("(%0.2lf, %0.2lf) is on the y-axis.\n", x, y);
  } else if (y == 0.00) {
    printf("(%0.2lf, %0.2lf) is on the x-axis.\n", x, y);
  } else if (x > 0 && y > 0) {
    printf("(%0.2lf, %0.2lf) is in Quadrant I.\n", x, y);
  } else if (x < 0 && y > 0) {
    printf("(%0.2lf, %0.2lf) is in Quadrant II.\n", x, y);
  } else if (x < 0 && y < 0) {
    printf("(%0.2lf, %0.2lf) is in Quadrant III.\n", x, y);
  } else {
    printf("(%0.2lf, %0.2lf) is in Quadrant IV.\n", x, y);
  }
  return 0;
}