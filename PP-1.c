#include <stdio.h>

int main() {

    int minutes = 0;
    double hours, days, years;
    
    printf("Enter the number of minutes:");
    scanf("%d", &minutes);

    hours = minutes / 60;
    days = hours / 24;
    years = days /365;

    printf("The number of minutes is %d\n", minutes);
    printf("The number of hours is %f\n", hours);
    printf("The number of days will be %f\n", days);
    printf("The number of years will be %f\n", years);

   return 0;
}