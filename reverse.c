#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define END '\0'
#define TERMINATOR_SIZE 1
#define BITS_IN_CHAR 8

char *reverse(char *message);

int main(int argc, char**argv){
   char message[999];
   scanf ("%s", message);
   assert(sizeof(message) < 1000);
   printf ("%s\n", reverse(message));
   return EXIT_SUCCESS;
}

char *reverse(char *message){
   int num_characters = 0;
   int counter = 0;
   char *buffer;
   char *index = message;
   char *reversed_message;

   while (*index != END){
      num_characters ++;
      index ++;
   }

   index--;
   buffer = malloc (BITS_IN_CHAR * (num_characters+TERMINATOR_SIZE));
   reversed_message = buffer;
   counter = num_characters;

   while (counter > 0){
      *reversed_message = *index;
      reversed_message ++;
      index --;
      counter --;
   }
   *reversed_message = END;
   return buffer;
}

