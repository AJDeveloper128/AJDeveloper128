#include <stdio.h>

int main(void) {
  const double KgPerPound = 2.20;
  const double OuncesPerPound = 16.0;
  float weight;
  printf("Please enter a weight in kilograms: ");
  scanf("%f", &weight);
  double weightInPounds = weight * KgPerPound;

  // Truncate fractional part to get the whole number of pounds
  int pounds = weightInPounds;
  weightInPounds = weightInPounds - pounds;

  // Convert remaining pounds to ounces
  double totalOunces = weightInPounds * OuncesPerPound;

  // Truncate fractional part to get whole ounces
  int ounces = totalOunces;
  totalOunces = totalOunces - ounces;
  printf("%d pounds , %d ounces , %.2f ounces remainder \n", pounds, ounces,
         totalOunces);
  return 0;
}