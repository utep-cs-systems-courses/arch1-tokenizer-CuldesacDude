#include <stdio.h>

#define Max_Limit 500 //not very sure what this does ? i know it is for the array

int main() {

  // printf() displays the string inside quotation

  //grab user's input
  char str[Max_Limit];
  printf("> ");
  fgets(str, Max_Limit,stdin);
  printf("%s",str);
  
  return 0;

}