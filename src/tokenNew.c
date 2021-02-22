#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

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



