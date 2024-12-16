#include <math.h>
#include <stdio.h>

// function prototype
int baseToDecimal(int, int);
int decimalToBase(int, int);
int validateInput(char, int, int, int, int);
int addition(int, int);
int subtraction(int, int);
int multiplication(int, int);
int division(int, int);

int main() {
  int base1, base2, num1, num2, result, total;
  char operator;
  // do-while loop to control the prompt to input and preform arithmetic task
  do {
    printf("Give input ($ to stop): ");
    scanf(" %c", &operator);  // Read the operator first
    if (operator== '$') {
      break;  // If the operator is '$', break the loop to stop the program
    }

    // Continue scanning the rest of the input
    scanf("%d %d %d %d", &base1, &num1, &num2, &base2);

    result = validateInput(operator, base1, base2, num1, num2);
    if (result == 1) {
      printf("%d %c %d (base %d) = ", num1, operator, num2, base1);

      // Convert both numbers from base1 to decimal
      num1 = baseToDecimal(base1, num1);
      num2 = baseToDecimal(base1, num2);

      printf("%d %c %d = ", num1, operator, num2);

      // Perform the arithmetic operation
      switch (operator) {
        case '+':
          total = addition(num1,
                           num2);  // add the two number together
          break;
        case '-':
          total = subtraction(num1, num2);  // subtract the two number together
          break;
        case '*':
          total =
              multiplication(num1, num2);  // multiply the two number together
          break;
        case '/':
          total = division(num1,
                           num2);  // divide the two numbers together
          break;
        default:
          printf("Invalid operation\n");
          return 0;
      }
      // turn the total back into the second base given
      total = decimalToBase(base2, total);
      printf(" %d (base %d)\n", total, base2);
    }
  } while (result < 2);

  return 0;
}
// Validate the input
int validateInput(char operator, int inputBase, int outputBase, int operand1,
                  int operand2) {
  // Check if the operator is valid
  if (operator!= '+' && operator!= '-' && operator!= '*' && operator!=
      '/' && operator!= '$') {
    printf("Invalid operator\n");
    return 0;
  }

  // Check if the input and output bases are within valid ranges (2-10)
  if (inputBase < 2 || inputBase > 10 || outputBase < 2 || outputBase > 10) {
    printf("Invalid base\n");
    return 0;
  }

  // Check if operand1 is valid for the input base
  while (operand1 > 0) {
    int digit = operand1 % 10;
    if (digit >= inputBase) {
      printf("Invalid digits in operand\n");
      return 0;
    }
    operand1 /= 10;
  }

  // Check if operand2 is valid for the input base
  while (operand2 > 0) {
    int digit = operand2 % 10;
    if (digit >= inputBase) {
      printf("Invalid digits in operand\n");
      return 0;
    }
    operand2 /= 10;
  }

  return 1;  // The input is valid
}

// Convert a number from base to decimal
int baseToDecimal(int b, int n) {
  int decimal = 0, i = 0, remainder;
  // continue to compute the remainder until the value n = 0
  while (n != 0) {
    remainder = n % 10;  // finds the remainder of n in terms of base 10
    decimal += remainder * pow(b, i);  // computes the values that make up the
                                       // number in terms of base 10
    n /= 10;
    i++;
  }

  return decimal;
}

// Convert the result back to base2
int decimalToBase(int b, int n) {
  int converted = 0, place = 1;

  while (n > 0) {
    int remainder = n % b;  // continues to take the modulus to find the
                            // remainder in terms of base b
    n /= b;
    converted +=
        remainder * place;  // uses the remainder to compute the values that add
                            // up to make the number in terms on base b
    place *= 10;
  }
  return converted;
}

// Arithmetic operations
int addition(int num1, int num2) { return num1 + num2; }

int subtraction(int num1, int num2) { return num1 - num2; }

int multiplication(int num1, int num2) { return num1 * num2; }

int division(int num1, int num2) { return num1 / num2; }
