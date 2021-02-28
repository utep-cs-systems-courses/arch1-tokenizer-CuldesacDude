#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){
  char str[] = "Hello World Test ";
  
  printf(">  %p ", &str);
  printf("\nCOPY_STR: %s\n",copy_str( str, sizeof(str)));
  //printf("\nTOKENIZE: %p\n", tokenize(str));//pointer of a pointer
  //print_tokens(tokenize(str));

  char **tok = (tokenize(str));

  print_tokens(tok);
  
  //free_tokens(tok);

  //print_tokens(tok);

  
  
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
  char *zeroPtr = '\0';
  
  if(sizeof(str)==0){
    return zeroPtr;
  }

  for(int i=0;i<sizeof(str);i++){
    
    if(non_space_char(str[i])==1){
      return &str[i];
    }
  }
  return zeroPtr;

}

char *word_terminator(char *word){
  char *zeroPtr = '\0';
  
  if(sizeof(word)==0){
    return zeroPtr;
  }
  for(int i=0;i<sizeof(word);i++){
    if(space_char(word[i])){
      return &word[i];
    }
  }
  return zeroPtr;
}

int count_words(char *str){

  if(sizeof(str)==0){
    return 0;
  }
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


char *copy_str(char *inStr , short len){\
  
  char *copyStr = (char*)malloc(sizeof(char)*(len+1));

  int i=0;
  while( i < len){
    copyStr[i] = inStr[i];
    i++;
  }
  copyStr[len] = '\0';

  //Debuggin code
  // printf("1> %p ", &inStr);
  //printf("2> %p ", &copyStr);
  /*if(copyStr == NULL){
    printf("Error memory no allocated");
    exit(0);
  }
  else{  
    for(int i=0; i<len;i++){
      printf("%p, ", copyStr[i]);
    }
  }*/
    
  return copyStr;
}

char **tokenize(char* str){
  
  int length = count_words(str); //count number of words in string. IN THIS CASE IT SHOULD BE 4
  printf("\n>LENGTH %i\n", length);
  char **char_array; //pointer of a pointer;
  char_array = (char**)malloc(sizeof(char*) * (length + 1)); //allocate memory for array
  int i = 0;
  while(i < length){ /*start filling array with pointers returned from copy_str*/
    str = word_start(str);
    
    int sizediff = word_terminator(str) - str;
    char_array[i] = copy_str(str,sizediff);
    
    str = word_terminator(str); //set str to start at the next space char for word_start
    i++;
  }
  char_array[i] = NULL; //sets a \0 at the end of the new array
  
  return char_array;
}
                   
void print_tokens(char **tokens){
  for(int i=0;tokens[i]!=NULL;i++){
    printf("<%s>",tokens[i]);
  }
}

void free_tokens(char **tokens){
  int i=0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}



