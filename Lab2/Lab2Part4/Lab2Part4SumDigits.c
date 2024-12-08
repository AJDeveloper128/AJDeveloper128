#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num, d1, d2, d3, d4, d5;
  printf("Enter an integer number between -99999 and 99999: ");
  scanf("%d", &num);
  num = abs(num);
  if (num < 10) {
    d1 = num;
    printf("The sum of the digits is: %d = %d\n", num, num);
  } else if (num < 100) {
    d2 = num % 10;
    num = num / 10;
    d1 = num;
    printf("The sum of the digits is: %d + %d = %d\n", d1, d2, d1 + d2);
  } else if (num < 1000) {
    d3 = num % 10;
    num = num / 10;
    d2 = num % 10;
    num = num / 10;
    d1 = num;
    printf("The sum of the digits is: %d + %d + %d = %d\n", d1, d2, d3,
           d1 + d2 + d3);
  } else if (num < 10000) {
    d4 = num % 10;
    num = num / 10;
    d3 = num % 10;
    num = num / 10;
    d2 = num % 10;
    num = num / 10;
    d1 = num;
    printf("The sum of the digits is: %d + %d + %d + %d = %d\n", d1, d2, d3, d4,
           d1 + d2 + d3 + d4);
  } else if (num < 100000) {
    d5 = num % 10;
    num = num / 10;
    d4 = num % 10;
    num = num / 10;
    d3 = num % 10;
    num = num / 10;
    d2 = num % 10;
    num = num / 10;
    d1 = num;
    printf("The sum of the digits is: %d + %d + %d + %d + %d = %d\n", d1, d2,
           d3, d4, d5, d1 + d2 + d3 + d4 + d5);
  } else {
    printf("Out of Range\n");
  }
  return 0;
}