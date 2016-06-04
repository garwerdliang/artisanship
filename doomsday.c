/*  Garwerd Liang
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by Garwerd
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

int dayOfWeek (int doomsday, int leapYear, int month, int day);

int main (int argc, char *argv[]) {
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

   assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);

   assert (dayOfWeek (THURSDAY,  TRUE,   2,  7)  == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY,  TRUE,   1,  31)  == TUESDAY);
   assert (dayOfWeek (MONDAY,  TRUE,   11,  11)  == FRIDAY);


   printf ("all tests passed - You are awesome!\n");
   return EXIT_SUCCESS;
}


// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek (int doomsday, int leapYear, int month, int day) {

   int dayOfWeek;
   int difference;
   difference = 0;

   //scanf ("%d %d", &day, &month);

   if (month == 1){
      difference = 90 - (day - 4);
   }
   if (month == 2){
      difference = 59 - (day - 4);
   }
   if (month == 3){
      difference = 31 - (day - 4);
   }
   if (month == 4){
      if (day < 4){
         difference = (4 - day);
      }else{
         difference = (day - 4);
   }
   }
   if (month == 5){
      difference = 30 + (day - 4);
   }
   if (month == 6){
      difference = 61 + (day - 4);
   }
   if (month == 7){
      difference = 91 + (day - 4);
   }
   if (month == 8){
      difference = 122 + (day - 4);
   }
   if (month == 9){
      difference = 153 + (day - 4);
   }
   if (month == 10){
      difference = 183 + (day - 4);
   }
   if (month == 11){
      difference = 214 + (day - 4);
   }
   if (month == 12){
      difference = 244 + (day - 4);
   }

   if (leapYear == TRUE){
     // printf ("true, %d\n", month);
      if (month < 3){
         difference++;
        // printf ("true, %d\n", month);
   }
   }
  //Caluculates the number of days between the date and chosen doomsday of
  //04/04

   dayOfWeek = (difference%7);

   if ((month < 4)||((month == 4) && (day <  4))){
      dayOfWeek = ((doomsday + ((7 - dayOfWeek)%7))%7);
   }else{
      dayOfWeek = ((doomsday + dayOfWeek) % 7);
   }

  //Modulates the amount of days to figure out dayOFWeek
   return (dayOfWeek);
}

