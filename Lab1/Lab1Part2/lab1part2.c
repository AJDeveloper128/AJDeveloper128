#include <stdio.h>
int main() {
  float originalBill;
  int tipPercentage;
  int pplSplitting;
  double totalBill;
  double perPerson;
  printf("Enter the original bill amount: ");
  scanf("%f", &originalBill);
  printf("Enter the tip percentage: ");
  scanf("%d", &tipPercentage);
  printf("Enter the number of people splitting the bill: ");
  scanf("%d", &pplSplitting);
  totalBill = ((float)tipPercentage / 100) * originalBill + originalBill;
  perPerson = totalBill / pplSplitting;
  printf("The total bill including tip is: %0.2f\n", totalBill);
  printf("Each person should pay: %0.2f\n", perPerson);

  return 0;
}