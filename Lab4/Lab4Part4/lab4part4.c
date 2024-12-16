#include <stdbool.h>
#include <stdio.h>
int main(void) {
  char userChar;
  int sum = 0, sign = 1;  // sign initialized to 1 for positive
  bool number = true;
  printf("Enter sequence of characters with numbers to add/subtract: ");
  do {
    scanf("%c", &userChar);
    if (number) {
      while (userChar < '0' || userChar > '9') {
        printf("Invalid! Re-enter number.\n");
        scanf("%c", &userChar);
      }
      sum += sign * (userChar - '0');
      number = false;
    } else {
      while (userChar != '+' && userChar != '-') {
        printf("Invalid! Re-enter sign.\n");
        scanf("%c", &userChar);
      }
      sign = (userChar == '+') ? 1 : -1;
      number = true;
    }

  } while (sum >= 0);
  printf("Sum fell below zero.\n");

  return 0;
}