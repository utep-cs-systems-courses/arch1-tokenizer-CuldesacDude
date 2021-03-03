#include <stdlib.h>
#include <stdio.h>
#include "history.h"

int main(){
  List *newList = init_history();
  add_history(newList,"add");
  add_history(newList,"this");
  add_history(newList,"pls");
  print_history(newList);
  printf("%s",get_history(newList,1));
  free_history(newList);
  print_history(newList);
  
}

List *init_history(){
  List *history_list = malloc(sizeof(List));
  history_list->root = NULL;
  return history_list;
}

void add_history(List *list, char *str){
  Item *NodeItem = (Item*)malloc(sizeof(Item)); 
  
  NodeItem->str = str;
  NodeItem->next = NULL;
  if(list->root == NULL){

    list->root = NodeItem;

    NodeItem->id = 1;
  }
  else{
    int IdCount = 2;
    Item *holder;
    holder = list->root;
    while(holder->next != NULL){
      IdCount++;
      holder = holder->next;
    }
    holder->next = NodeItem;
    NodeItem->id = IdCount;
  }
}

char *get_history(List *list, int id){
  if(id == 1){
    list->root->str;//sends the first item
  }
  Item *holder = list->root;
  while(holder != NULL){
    if(holder->id == id){
      return holder->str;
    }
    holder = holder->next;
  }
  return NULL;
}

void print_history(List *list){
  Item *holder = list->root;
  while(holder != NULL){
    printf("ID<%i> STR[%s]\n", holder->id, holder->str);
    holder = holder->next;
  }
}

void free_history(List *list){
  free(list);
}




