#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "tokenNew.c"

int main (){

  //SPACE_CHAR: first
  printf("\n>Space_Char: %d",space_char('f')); // 0
  printf("\n>Space_Char: %d", space_char(' ')); // 1

  //NON-SPACE_CHAR; TEST 'wrong?'
  printf("\n>Non_Space_Char: %d", non_space_char('g'));
  printf("\n>Non_Space_Char: %d\n",non_space_char(' '));

  //WORD_START
  char str1[] = "   Hello";
  char *ptr = word_start(str1);

  printf("1: %p\n",ptr);
  printf("2: %p\n",&str1[3]);
  printf("LETTER: %c\n", str1[3]);

  //WORD_TERMINATOR

  char str2[] = "Hello ";
  char *ptr2 = word_terminator(str2);

  printf("1: %p\n",ptr2);
  printf("2: %p\n",&str2[5]);
  printf("LETTER: %c\n",str2[5]);

  //WORD_COUNTER
  printf("\nWord_counter: %i\n",count_words("Hello World"));

  //COPY_STR
  char cStr[] = "this is a test";
  printf("\nCopy_str: \n", copy_str(cStr,sizeof(cStr)));
  
  return 0;

}
