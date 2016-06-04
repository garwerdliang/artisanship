//Garwerd Liang
//22/03/16
//wondorous function

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0

int printWondrous (int start);
void test(void);

int main (int argc, char *argv[]) {
   int start;
   int counter;
   test();
   scanf ("%d", &start);
   counter = printWondrous(start);
   printf("%d\n", counter);
   return EXIT_SUCCESS;
}

int printWondrous (int start){
   int stop;
   int counter;
   stop = FALSE;
   counter = 0;
   assert(start>0);
   while (stop == FALSE){
      counter++;
      if (start == 1){
         stop = TRUE;
      }else if ((start%2) == 0){
         start = (start/2);
      }else{
         start = (start*3) + 1;
      }
   }
   return counter;
}

void test(void){
   assert(printWondrous(1) == 1);
   assert(printWondrous(2) == 2);
   assert(printWondrous(10) == 7);
   assert(printWondrous(649) == 145);
   assert(printWondrous(3711) == 238);
}