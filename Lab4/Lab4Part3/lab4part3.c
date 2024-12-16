#include <math.h>
#include <stdio.h>

int main() {
  int lower, upper, is_prime, found_prime;

  // Input validation: Ensure valid non-negative integers where lower <= upper
  printf("Enter the lower and upper bounds of the interval: ");
  scanf("%d %d", &lower, &upper);

  while (lower < 0 || upper < 0 || lower > upper) {
    printf(
        "Invalid Input. Please enter two non-negative integers where the first "
        "is less than or equal to the second: ");
    scanf("%d %d", &lower, &upper);
  }

  // Prime checking and displaying prime numbers
  printf("Prime numbers in the interval [%d, %d]: ", lower, upper);
  found_prime = 0;  // Flag to check if any primes are found

  for (int i = lower; i <= upper; i++) {
    is_prime = 1;  // Assume the number is prime
    if (i < 2) {
      is_prime = 0;  // Numbers less than 2 are not prime
    } else {
      for (int j = 2; j <= sqrt(i); j++) {
        if (i % j == 0) {
          is_prime = 0;  // If divisible, it's not prime
          break;
        }
      }
    }

    if (is_prime) {
      if (found_prime) {
        printf(", ");
      }
      printf("%d", i);
      found_prime = 1;
    }
  }

  if (!found_prime) {
    printf("No prime numbers found in the interval.");
  }

  printf("\n");
  return 0;
}
