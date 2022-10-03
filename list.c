// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"	

list_t *list_alloc() {
   list_t* list = (list_t*) malloc(sizeof(list_t));   //CAST TYPE FOR COMPILER COMPRHENSION THAT IM DOING RIGHT (LIST_T*)
   list-> head = NULL;
   return list; 
   }

node_t *node_alloc(elem val){
  node_t *node = (node_t*) malloc(sizeof(node_t));
  node->value = val;
  node->next = NULL;
  return node;
}

void list_free(list_t *l) {
  node_t *curr, *tempNextNode;
  curr = l-> head;

while(curr != NULL){
  tempNextNode = curr->next;
  node_free(curr);
  curr = tempNextNode;
  if (curr == NULL)
    printf("I'm Empty!\n");
  }
}

void node_free(node_t *node){
  free(node);
}

void list_print(list_t *l) {
node_t *curr = l->head;
printf("List| ");

while (curr!= NULL){
	printf("%d ", curr->value);
	curr = curr->next; 
 }
printf("\n");

}


int list_length(list_t *l) { 
   node_t *curr;
   int length = 0;
   curr = l->head;

   if(curr==NULL){
     printf("We are working with an empty list!\n");
   }
   while(curr != NULL){
    length++;
    curr = curr->next;
    
   }

return length; 
}

void list_add_to_back(list_t *l, elem val) {

  node_t *curr = l->head;
  node_t *newNode = node_alloc(val);

  while(curr->next != NULL ){
    curr = curr->next;
    if (curr->next == NULL){
      curr->next = newNode;
      newNode->next = NULL;
      }  
   }
}


void list_add_to_front(list_t *l, elem value) {
     node_t* temp = l-> head;
     node_t* newNode = node_alloc(value);
     l->head = newNode;
     newNode-> next = temp;
}

void list_add_at_index(list_t *l, elem value, int index) {
    node_t *curr = l->head;
    node_t *newNode = node_alloc(value);
    
    node_t *temp;
    int counter = 0; 

    //initialize counter to compare with index value
    while(counter <= index){
      if (index == 0 && counter == 0){
        list_add_to_front(l,value);
      }
      else if (counter == index){
        temp = curr->next;
        curr->next = newNode;
        newNode->next = temp;
      }  
      else{
        curr = curr->next;
      }
      counter++;
    }
}

elem list_remove_from_back(list_t *l) { 
    
    node_t *currNode = l->head, *tempNextNode;
    elem temp_val; 

    while(currNode->next != NULL ){
      tempNextNode = currNode->next;
      temp_val = tempNextNode->value;
      if (tempNextNode->next == NULL){
        printf("\nFreeing Node From List...\n");
        node_free(tempNextNode);
        currNode->next = NULL;
        // currNode = currNode->next;
      }
      else{
        currNode = currNode->next;
      }

    }
    printf("\nReturn Temporary Value: %d\n", temp_val);

    return temp_val; 
  }

elem list_remove_from_front(list_t *l) { 
  node_t *curr =  l->head, *temp;
  temp = curr->next;
  l->head = temp;
  node_free(curr);
  return temp->value; 
  }

elem list_remove_at_index(list_t *l, int index) { 
    node_t *currNode, *tempNextNode, *prevNode;
    elem temp_val;
    int counter, length; 

    currNode = l->head;
    counter = 0;
    length = list_length(l); 

    if(index > length){
        printf("index is too big!\n");
        return -1; 
      }
    //initialize counter to compare with index value
    while(counter <= index){
      if (index == 0 && counter == 0){
        temp_val = currNode->value;
        list_remove_from_front(l);
        return temp_val;
      }
      else if (counter == index){
      temp_val = currNode->value;
      prevNode->next = tempNextNode; 
      node_free(currNode);
      }
      prevNode = currNode; 
      currNode = prevNode->next;
      tempNextNode = currNode->next;
      counter++;
    }
  return temp_val; }

bool list_is_in(list_t *l, elem value) {
  node_t *curr;
  int counter, length;

  curr = l->head;
  length = list_length(l); 
  for (counter = 0; counter < length; counter++ ){
    if (curr->value == value)
      return true;
    else
      curr = curr->next;
    }  
  return false;
  }

elem list_get_elem_at(list_t *l, int index) { 
  node_t *curr;
  int counter, length;

  curr = l->head;
  length = list_length(l) + 1;
  for (counter = 0; counter <= length; counter++ ){
    if (counter == index)
      return curr->value;
    else 
      curr = curr->next;
    }  
  
 }


int list_get_index_of(list_t *l, elem value) {
  node_t *curr;
  int counterIndex, length;

  curr = l->head;
  length = list_length(l) + 1;

  if (curr == NULL)
    return -1;

  for (counterIndex = 0; counterIndex <= length; counterIndex++ ){
    if (curr->value == value)
      return counterIndex;
    else 
      curr = curr->next;
    }  
  }

