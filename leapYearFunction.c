//Name: Augusdn
//Date: 31 March 2015
//Program that test for leap year with leapYearFunction

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR 1582

int isLeapYear (int year);
int year;

int main (int argc, char* argv[]){


printf ("please enter the year you are interested in\n");
scanf ("%d", &year);

assert (year >= START_OF_GREG_CALENDAR);
   if (isLeapYear(year) == 0){
      printf ("%d is not a leap year!\n", year);
   }
   if (isLeapYear(year) == 1){
      printf ("%d is a leap year!\n", year);
   }

return EXIT_SUCCESS;
}

int isLeapYear (int year) {
   int isLeapYear;

   if ((year % 4) == 0){
      if (year % 100 == 0){
         if (year % 400 == 0){
            isLeapYear = 1;
         } else {
            isLeapYear = 0;
          }
      } else {
         isLeapYear = 1;
        }
   } else {
         isLeapYear = 0;
     }
   return (isLeapYear);
}
