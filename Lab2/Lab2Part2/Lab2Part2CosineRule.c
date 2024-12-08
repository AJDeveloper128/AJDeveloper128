#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

int main() {
  double x1, x2, y1, y2, cos_theta, dot_product, magnitude_A, magnitude_B,
      theta_radian, theta_degrees;
  printf("Enter point A as (x1,y1): ");
  scanf("%lf,%lf", &x1, &y1);
  printf("Enter point B as (x2,y2): ");
  scanf("%lf,%lf", &x2, &y2);
  dot_product = (x1 * x2) + (y1 * y2);
  magnitude_A = sqrt((x1 * x1) + (y1 * y1));
  magnitude_B = sqrt((x2 * x2) + (y2 * y2));
  cos_theta = dot_product / (magnitude_A * magnitude_B);
  theta_radian = acos(cos_theta);
  theta_degrees = (theta_radian * 180) / M_PI;
  printf(
      "The angle theta between the two points is: %0.3lf radians & %0.2lf "
      "degrees\n",
      theta_radian, theta_degrees);

  return 0;
}