/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by Hyun Woo Lee
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
 
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6
 
#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

#define START_OF_GREG_CALENDAR 1582
 
int dayOfWeek (int doomsday, int leapYear, int month, int day);
int leapYearCheck(int iYear);
int isLeapYear(int year);
int doomsDayCheck(int iYear);
 
int main (int argc, char *argv[]) {
   //assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);

   printf ("Type in 6 digits of numbers in YEAR MONTH DAY format with spaces.\nExample: 2016 03 23 = YYYY MM DD\n");
   
   int iYear, iMonth, iDay;
   int leapYear, doomsDay;
   int day;
   
   char a[7][10];
   strcpy(a[0], "Thursday");
   strcpy(a[1], "Friday");
   strcpy(a[2], "Saturday");
   strcpy(a[3], "Sunday");
   strcpy(a[4], "Monday");
   strcpy(a[5], "Tuesday");
   strcpy(a[6], "Wednesday");
   
   scanf("%d %d %d", &iYear, &iMonth, &iDay);
   printf("Input is %d %d %d\n\n", iYear, iMonth, iDay);
   
   leapYear = leapYearCheck(iYear);
   if(leapYear == 3){
      printf("FAILED LEAP YEAR\n");
   }
   
   doomsDay = doomsDayCheck(iYear);
   
   printf("doomsday of %d is %s\n", iYear, a[doomsDay]);

   day = dayOfWeek (doomsDay, leapYear, iMonth, iDay);
   
   printf("DOOMSDAY IS %d\n", day);

   printf("\n\n%d/%d/%d is %s\n", iYear, iMonth, iDay, a[day]);
      
   return EXIT_SUCCESS;
}
 
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
 
int dayOfWeek (int doomsday, int leapYear, int month, int day) {
   int dayOfWeek;

   int daysToEndOfFeb = 31 + 28;
   int daysToInputDay = 0; 
   
   if (month == 1) {
      daysToInputDay = day;
   }
   
   if (month == 2) {
      daysToInputDay = day + 31;
   }
   
   if (month == 3) {
      daysToInputDay = day + 31 + 28;
   }
   
   if (month == 4) {
      daysToInputDay = day + 31 + 28 + 31;
   }
   
   if (month == 5) {
      daysToInputDay = day + 31 + 28 + 31 + 30;
   }
   
   if (month == 6) {
      daysToInputDay = day + 31 + 28 + 31 + 30 + 31;
   }
   
   if (month == 7) {
      daysToInputDay = day + 31 + 28 + 31 + 30 + 31 + 30;
   }
   
   if (month == 8) {
      daysToInputDay = day + 31 + 28 + 31 + 30 + 31 + 30 + 31;
   }
   
   if (month == 9) {
      daysToInputDay = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
   }
   
   if (month == 10) {
      daysToInputDay = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
   }
   
   if (month == 11) {
      daysToInputDay = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
   }
   
   if (month == 12) {
      daysToInputDay = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
   }
   
   if (leapYear == FALSE) {
      dayOfWeek = ((doomsday + DAYS_PER_WEEK) - (((daysToEndOfFeb - daysToInputDay) % DAYS_PER_WEEK) + DAYS_PER_WEEK) % DAYS_PER_WEEK) % DAYS_PER_WEEK;
   } else {
      if (month <= 2) {
         dayOfWeek = ((doomsday + DAYS_PER_WEEK) - (((DAYS_PER_WEEK + daysToEndOfFeb + 1) - daysToInputDay) % DAYS_PER_WEEK)) % DAYS_PER_WEEK;
      } else {
         dayOfWeek = ((doomsday + DAYS_PER_WEEK) - (DAYS_PER_WEEK + ((daysToEndOfFeb - daysToInputDay) % DAYS_PER_WEEK))) % DAYS_PER_WEEK;
      }
   }
   
   return (dayOfWeek);
}

int leapYearCheck(int year){
   assert (year >= START_OF_GREG_CALENDAR);
   if (isLeapYear(year) == 0){
      printf ("%d is not a leap year!\n", year);
      return 0;
   } 
   if (isLeapYear(year) == 1){
      printf ("%d is a leap year!\n", year);
      return 1;
   }
   return 3;
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

int doomsDayCheck (int year){
   int tmpYear;
   int a, b, c, d;
   int anchor;
   int doomsDay;
   
   tmpYear = year % 100;
   a = tmpYear / 12;
   b = tmpYear % 12;
   c = b / 4;
   
   d = a + b + c;
   tmpYear = year % 400;
   
   if( tmpYear >= 0 && tmpYear<= 99 ){
      anchor = 5;
   } else if( tmpYear >= 100 && tmpYear<= 199 ){
      anchor = 3;
   } else if( tmpYear >= 200 && tmpYear<= 299 ){
      anchor = 1;
   } else if( tmpYear >= 300 && tmpYear<= 399 ){
      anchor = 6;
   }
   
   doomsDay = (anchor + d) % 7;
   
  printf("a b c are %d %d %d %d\n", a, b, c, d);
   printf("anchor is %d\n", anchor);
   printf("doomsday is %d\n", doomsDay);
   
   return doomsDay;
}
