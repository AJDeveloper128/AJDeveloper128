#include <stdio.h>

int main() {
  int input, d1, d2, d3, d4;
  printf("Enter a number to convert to Base 2: ");
  scanf("%d", &input);
  if (input > 0 && input < 15) {
    d1 = (input / 8) % 2;
    d2 = (input / 4) % 2;
    d3 = (input / 2) % 2;
    d4 = input % 2;
    printf("The four digits of that number are as follows:\n");
    printf(
        "Most significant digit: %d\nNext digit: %d\n Next digit %d\nLeast "
        "significant digit: %d\n",
        d1, d2, d3, d4);
  
  } else {
    printf("Error: Please enter a number between 0 and 15.\n");
  }
  return 0;
}