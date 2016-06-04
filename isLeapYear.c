//Garwerd Liang
//08/03/2016
//Checks if a year is a leap year

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0

int isLeapYear (int year);
void testLeap(void);

int main (int argc, char*argv[]) {
   int year;
   int leap;
   testLeap();
   printf ("please enter the year you are interested in\n");
   scanf ("%d", &year);
   leap = isLeapYear(year);
   if (leap == TRUE) {
      printf ("%d is  a leap year\n",year);
   }  else {
      printf ("%d is not a leap year\n",year);
   }
   return EXIT_SUCCESS;
}

int isLeapYear (int year) {
   int isLeap;
   isLeap = FALSE;
   if ((year % 400) == 0){
      isLeap = TRUE;
   }else if (year % 100 == 0){
   }else if (year % 4 == 0){
      isLeap = TRUE;
   }
   return isLeap;
 }

 void testLeap(void){
   assert(isLeapYear(2004) == TRUE);
   assert(isLeapYear(2005) == FALSE);
   assert(isLeapYear(1996) == TRUE);
   assert(isLeapYear(1000) == FALSE);
   assert(isLeapYear(2013) == FALSE);
   assert(isLeapYear(2012) == TRUE);
   assert(isLeapYear(2000) == TRUE);
 }
