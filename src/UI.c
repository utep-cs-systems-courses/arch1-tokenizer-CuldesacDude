#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenNew.c"
#include "history.c"

#define Limit 100
int str_length(char *str);

int main(){
  char userInput[Limit];
  char **token;
  List *history = init_history();
  printf("x : quits program, h : print history\n");
  printf("enter a string to be tokenized \n");
  while(*userInput != 'x'){
    
    printf("> ");

    fgets(userInput, Limit, stdin);

    if(*userInput!='h'&&*userInput != 'x'){
      token = tokenize(userInput);
      printf("user string tokenized\n");
      print_tokens(token);
      free_tokens(token);
      printf("\n adding str to history\n");
      add_history(history, copy_str(userInput, sizeof(userInput)));
    }
    if(*userInput == 'h'){
      print_history(history);
    }
    if(*userInput == 'x'){
      break;
    }
  }
  return 0;
}
