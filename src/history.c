#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer."

List *init_history(){
  List *list = malloc(sizeof(List));
  return list;
}

void add_history(List *list, char *str){
  Item *newItem = (Item*)malloc(sizeof(Item)); 
  
  newItem->str = str; newItem->next = NULL;

  if(list->root == NULL){//if no node, we add one to the start

    list->root = newItem;

    newItem->id = 1;
  }
  else{
    int Count = 2;
    Item *curr;
    curr = list->root;
    while(curr->next != NULL){
      Count++;
      curr = curr->next;
    }
    curr->next = newItem;
    newItem->id = Count;
  }
}

char *get_history(List *list, int id){
  if(id == 1){
    list->root->str;//sends the first item
  }
  Item *curr = list->root;

  while(curr != NULL){
    if(curr->id == id){
      return curr->str;
    }
    curr = curr->next;
  }
  return NULL;
}

void print_history(List *list){
  Item *curr = list->root;
  while(curr != NULL){
    printf("ID: %i string: %s \n", curr->id, curr->str);
    curr = curr->next;
  }
}

void free_history(List *list){//this is not working properly
  
  free(list);
  
}




