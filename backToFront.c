/*
 *  backToFront.c
 *  2013s1 Prac Exam
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

// Complete this function and submit this file ONLY
// for the prac exam.  Do not change the other supplied
// as you will not be submitting them.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "backToFront.h"

nodePtr backToFront (nodePtr first) {
   nodePtr curr = first;
   nodePtr prev;
   if (curr == NULL){
   }else if(curr->next == NULL){
   }else{
      while(curr != NULL && curr->next != NULL){
         prev = curr;
         curr = curr->next;
         }
      prev->next = NULL;
      curr->next = first;   
   }
   return curr;
}
