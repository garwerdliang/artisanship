#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "flip.h"

// 1 2 X

void flip (list l){
	link prev = l->head;
	link curr;
	link temp;
	if (prev == NULL){
	}else if(prev->next == NULL){
	}else{
        curr = prev->next;
        l->head = curr;
		while (prev!=NULL&&curr!=NULL){
           temp = curr->next;
           if (curr->next != NULL){
              if (curr->next->next == NULL){
              	 prev->next = curr->next;
              	 curr->next = prev;
              }else{
                 prev->next = curr->next->next;
                 curr->next = prev;
              }
           }else{
           	  prev->next = curr->next;
              curr->next = prev;
           }
           
           prev= temp;
           if (prev!=NULL){
              curr = prev->next;
           }
		}
	}
}# artisanship
