#include <stdio.h>

int main() {
  int total_minutes, hours, minutes, rounded_minutes;
  printf("Enter Total Minutes: ");
  scanf("%d", &total_minutes);
  hours = total_minutes / 60;
  minutes = total_minutes % 60;
  if (minutes <= 7) {
    rounded_minutes = 0;
  } else if (minutes >= 8 && minutes <= 22) {
    rounded_minutes = 15;
  } else if (minutes >= 23 && minutes <= 37) {
    rounded_minutes = 30;
  } else if (minutes >= 38 && minutes <= 52) {
    rounded_minutes = 45;
  } else {
    rounded_minutes = 0;
  }
  printf("That is Equivalent To:\n %d hours and %d minutes\n", hours,
         rounded_minutes);

  return 0;
} 