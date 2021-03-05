#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/*int main (){
  char str[100] = "THIS IS A TEST sdsfad asdfdas asdffasd asdfadfs";
  print_tokens(tokenize(str));

  }*/
 

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

int count_words(char *str){

  if(sizeof(str)==0){
    return 0;
  }
  int counter = 0;
  int mode = 0; // a switch system, not very efficient but it works
  for(; *str!='\0';str++){
    if(non_space_char(*str) == 1){ //looks for the first letter, once found switch mode's
      mode = 1;
    }
    /*looks for the next space, if found an empty "space" we have iterate
      thru a word, so we add 1 a counter */
    if((space_char(*str)==1)&&(mode == 1)){
      counter ++;
      mode = 0;
    }
  }
  /* if there is only one word with no spaces at the ends*/
  if(mode == 1){ 
    counter ++;
  }
  return counter;
}

char **tokenize(char* str){
  
  int length = count_words(str); //count number of words in string.
  printf("\n>LENGTH %i\n", length);
  char **char_array; //pointer of a pointer;
  char_array = (char**)malloc(sizeof(char*) * (length + 1)); //allocate memory for array
  int i = 0;
  while(i < length){ /*start filling array with pointers returned from copy_str*/
    str = word_start(str);
    
    int Diff = word_terminator(str) - str;
    char_array[i] = copy_str(str,Diff);
    
    str = word_terminator(str); //set str to start at the next space char for word_start
    i++;
  }
  
  
  char_array[i] = NULL; //sets a \0 at the end of the new array
  /* for(i=0; i<length;i++){
    printf("%s",char_array[i]);
  }
  printf("%s",char_array[i]);*/
  return char_array;
}

char *copy_str(char *inStr , short len){\
  
  char *copyStr = (char*)malloc(sizeof(char)*(len+1)); //malloc allocates memory 

  int i=0;
  while( i < len){ //while loop copies the string
    copyStr[i] = inStr[i];
    i++;
  }
  copyStr[len] = '\0'; //adds a zero terminator to the end of pointer array
  return copyStr;
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
  free(tokens);//this should free the last space
}



