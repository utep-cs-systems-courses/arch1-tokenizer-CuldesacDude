#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c=='\t'||c==' '){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  if(c != '\t' || c!= ' '){
    return 1;
  }
  else if(c == '\0'){
    return 0;
  }
  return 0;
}

char word_start(char *str){
  char blank = ' ';
  int  holder;
  int init = 1;
  while (init == 1){
    if(*(str + holder) == blank){
      return (str+(holder+1));
   
    }
    if(str +holder == 0){
      *str = 0;
      break;
    }
    else{
      holder++;
    }
  }
  return str;
}

char *word_terminator(char *word){
  return 0;
}

int count_words(char *str){
  int counter;
  counter = 0;

  for(int i=0; str[i] !="\0"; i++){
    if(str[i]==' ';||str[i]=='\n'||str[i]=='\t'){
      counter++;
    }
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



