#include <math.h>
#include <stdio.h>

int main() {
  int terms;
  double estimate = 0.0;

  // Input validation: Ensure the user enters a non-negative integer
  printf("Enter the number of terms for π approximation: ");
  scanf("%d", &terms);
  while (terms < 0) {
    printf("Please enter a non-negative integer: ");
    scanf("%d", &terms);
  }

  // Loop through the number of terms to calculate the series
  for (int i = 0; i < terms; i++) {
    if (i % 2 == 0) {
      estimate += 1.0 / (2 * i + 1);  // Add when i is even
    } else {
      estimate -= 1.0 / (2 * i + 1);  // Subtract when i is odd
    }
  }

  // Multiply the result by 4 to get the approximation of π
  estimate *= 4;
  estimate = (round(estimate * 1000) / 1000);

  // Output the estimated value of π
  printf("Estimated value of π after %d terms: %.3f\n", terms, estimate);

  return 0;
}
