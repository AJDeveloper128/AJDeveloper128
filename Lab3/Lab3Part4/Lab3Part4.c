#include <math.h>
#include <stdio.h>
int main() {
  double quiz1, quiz2, assignment, exam;
  double weighted_average, final_score, bonus;
  char grade;
  printf("Enter marks for Quiz 1 (out of 20): ");
  scanf("%lf", &quiz1);  // Error: Missing &
  printf("Enter marks for Quiz 2 (out of 20): ");
  scanf("%lf", &quiz2);
  printf("Enter marks for the Assignment (out of 50): ");
  scanf("%lf", &assignment);
  printf("Enter marks for the Exam (out of 100): ");
  scanf("%lf", &exam);
  weighted_average =
      ((quiz1 + quiz2) / 40 * 0.2 + assignment / 50 * 0.3 + exam / 100 * 0.5) *
      100;
  bonus = ceil(weighted_average * 0.1);  // Bonus calculation
  final_score = weighted_average + bonus;
  printf("Weighted Average: %.2f\n", weighted_average);
  printf("Bonus: %.2f\n", bonus);
  printf("Final Score: %.2f\n", final_score);
  if (final_score >= 90) {
    grade = 'A';  // Error: Incorrect use of double quotes for char
  } else if (final_score >= 80 && final_score < 90) {
    grade = 'B';
  } else if (final_score >= 70 && final_score < 80) {
    grade = 'C';
  } else if (final_score >= 60 && final_score < 70) {
    grade = 'D';
  } else {
    grade = 'F';
  }
  printf("Your final grade is: %c\n", grade);
  return 0;
}
