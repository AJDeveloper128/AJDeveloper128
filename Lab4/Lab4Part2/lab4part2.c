#include <stdio.h>

int main() {
  int a, b, remainder;

  // Input validation: Ensure both inputs are non-negative integers using a
  // while loop
  printf("Enter two non-negative integers: ");
  int result = scanf("%d %d", &a, &b);

  // Keep asking for input until both a and b are valid non-negative integers
  while (result != 2 || a < 0 || b < 0) {
    printf("Invalid input. Please enter two non-negative integers: ");
    while (getchar() != '\n');  // Clear the input buffer
    result = scanf("%d %d", &a, &b);
  }

  // Euclidean algorithm to find the GCD using a for loop
  while (b != 0) {
    remainder = a % b;
    a = b;
    b = remainder;
  }

  // The GCD is now stored in 'a'
  printf("The GCD of the entered numbers is %d.\n", a);

  return 0;
}
