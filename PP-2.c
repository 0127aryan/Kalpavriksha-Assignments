#include<stdio.h>

int main() {
   int hoursWorked = 0, weeklyPay = 0, overtimeHours = 0, grossPay = 0;
   double weeklyPayAfterTax = 0, weeklyPayAfterTax2 = 0, weeklyPayAfterTax3 = 0;
   
  printf("Enter the number or hours you worked:");
  scanf("%d", &hoursWorked);
   
  overtimeHours = hoursWorked - 40;
   
   
   
   
  if(hoursWorked > 40){
      printf("\nYour Overtime hours are:%d", overtimeHours);
      printf("\nYour gross pay will be 480 plus overtime hours");
      weeklyPay = overtimeHours*19 + 40*12;
      printf("\nYour gross pay will be:%d", weeklyPay);
      
  } else {
      printf("\nyour base pay will be 12$");
      weeklyPay = hoursWorked*12;
      printf("\nYour weekly pay will be:%d", weeklyPay);
  }
  
  if(weeklyPay<300){
      printf("\ntax rate will be 15 percent");
    //   printf("test: %d", (weeklyPay/15));
      weeklyPayAfterTax = weeklyPay -(0.15 * weeklyPay);
      printf("\nWeekly pay after tax deduction will be %lf", weeklyPayAfterTax);
      }
      else if(300>=weeklyPay && weeklyPay<=450){
          printf("\nTax rate will be 20 percent");
          weeklyPayAfterTax = weeklyPay -(0.2 * weeklyPay);
          printf("\nWeekly pay after tax deduction will be %lf", weeklyPayAfterTax);
          
      }
      else if(weeklyPay > 450) {
          printf("\ntax rate will be 25 percent");
          weeklyPayAfterTax = weeklyPay - (0.25 * weeklyPay);
          printf("\nWeekly pay after tax deduction will be %lf", weeklyPayAfterTax);
      }
   
   return 0;
}