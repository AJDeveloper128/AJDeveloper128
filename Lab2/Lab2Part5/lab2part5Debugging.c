#include <stdio.h>

int main(void) {
  int encComb;
  printf("Enter an encrypted 4-digit combination: ");
  scanf("%d", &encComb);
  // Determine the 4 digits of the encrypted combinaiton
  int d4, d3, d2, d1;
  d4 = encComb % 10;
  encComb = encComb / 10;

  d3 = encComb % 10;
  encComb = encComb / 10;

  d2 = encComb % 10;
  encComb = encComb / 10;

  d1 = encComb;

  // printing the decryped combination : d4 and d1 are swaped .
  // d3 and d2 are 9 s complemented
  printf("\nThe real combination is: %d%d%d%d\n", d4, 9 - d2, 9 - d3, d1);

  return 0;
}
