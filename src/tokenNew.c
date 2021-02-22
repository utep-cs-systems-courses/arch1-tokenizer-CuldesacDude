#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

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
  printf("\n%i\n",count_words(" Hello world "));
  
  return 0;
}

int space_char(char c){
  if(c=='\t'||c==' '||c=='\n'){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  int check;
  if(c=='\t'|| c==' ' || c=='\n'){
    check = 0;
  }
  else{
     check = 1;
  }
  return check;
}

char *word_start(char *str){
  
  if(sizeof(str)==0){
    return '\0';
  }

  for(int i=0;i<sizeof(str);i++){
    
    if(non_space_char(str[i])==1){
      return &str[i];
    }
  }
  return '\0';

}

char *word_terminator(char *word){
  if(sizeof(word)==0){
    return '\0';
  }
  for(int i=0;i<sizeof(word);i++){
    if(space_char(word[i])){
      return &word[i];
    }
  }
  return '\0';
}

int count_words(char *str){
  int counter = 0;
  int mode = 0;
  for(; *str!='\0';str++){
    if(non_space_char(*str) == 1){
      mode = 1;
    }
   
    if((space_char(*str)==1)&&(mode == 1)){
      counter ++;
      mode = 0;
    }

  }
  if(mode == 1){
    counter ++;
  }
  return counter;
}


char *copy_str(char *inStr , short len){
  return 0;
}

char **tokenize(char* str){
  return 0;
}

void print_tokens(char **tokens){
  int init = 0;
  int sect = 1;
  while (sect ==1 ){
    if(tokens[init]!=NULL){
      printf("%c",*tokens[init]);
    }
    else{
      sect = 2;
    }
  }
}

void free_tokens(char **tokens){

}



