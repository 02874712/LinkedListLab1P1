// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
}

void list_free(list_t *l){
  node_t *head, *node; 
  head = l->head;

  // Checks if the system is NULL to avoid double free
  if (l == NULL){return;}
  
  while(head != NULL){
    node = head;
    head = head->next;
    node_free(node);
  }
  l->head = NULL;
}

node_t *node_alloc(elem val){
  node_t *node = (node_t*) malloc(sizeof(node_t));
  node->value = val;
  node->next = NULL;
  return node;
}

void node_free(node_t *node){
  free(node);
}

void list_print(list_t *l){
node_t *node = l->head;

printf("\nList|");

if (node == NULL){
  printf("Empty!\n");
}

while (node != NULL){
  printf("%d ", node->value);
  node = node->next;
}
}    

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l){
  node_t *node = l->head;
  int length = 0;

  while( node != NULL){
    node = node->next;
    length++;
  }

  return length;
}

void list_add_to_back(list_t *l, elem value){
  node_t *newNode, *head;
  newNode = node_alloc(value);
  head = l->head;

  if(head == NULL){
    l->head = newNode;
    return;
  }

  while(head->next != NULL){
    head = head->next;
  }

  head->next = newNode;
}

void list_add_to_front(list_t *l, elem value){
  node_t *newNode, *head;
  newNode = node_alloc(value);
  head = l->head;

  if(head == NULL){
  l->head = newNode;
  return;
  }

  newNode->next = head;
  l->head = newNode;
}

void list_add_at_index(list_t *l, elem value, int index){
  node_t *newNode = node_alloc(value);
  node_t *prevNode = NULL;
  node_t *node = l->head;

  int length = list_length(l);
//p  int counter = 0;

  // Check for a negative index and if the list is empty to add into list
//p  if (index < 0 ){
    index = index + length;
    if (node == NULL){
      list_add_to_front(l, value);
      return;
    }
  }
  
  // Check if index is valid now
//p  if (index < 0) {
      return; // or handle error appropriately
  }

  if(index > length){
    list_add_to_back(l, value);
    return;
  }
  // Checks when the index is the head
//p  if (index == 0){        
    newNode->next = node;
    l->head = newNode;
    return;
  }

  while(counter < index){
    prevNode = node;
    node = node->next;
    counter++;
  }

  prevNode->next = newNode;
  newNode->next = node;

}

elem list_remove_from_back(list_t *l){
  node_t *node, *prevNode;
  elem removedElem;

  node = l->head;

  if (list_length(l) == 0){
    return -1;
  } 

  if(node->next == NULL){
    removedElem = node->value;
    l->head = NULL;
    return removedElem;
  }

  while(node->next != NULL){
  prevNode = node;
  node = node->next;
  }
  removedElem = node->value;
  prevNode->next = NULL;
  node_free(node);

return removedElem;
}

elem list_remove_from_front(list_t *l){
  node_t *node, *nextNode;
  elem removedElem;

  node = l->head;
  nextNode = NULL;

  if (list_length(l) == 0){
    return -1;
  } 

  if (node->next == NULL){
    removedElem = node->value;
    l->head = NULL;
    node_free(node);
    return removedElem;
  }

  removedElem = node->value;
  nextNode = node->next;
  node_free(node);
  l->head = nextNode;

return removedElem;
}

elem list_remove_at_index(list_t *l, int index) {
//p    int counter = 0;
    int length = list_length(l);
    elem removedElem;
    node_t *node = l->head;
    node_t *prevNode = NULL;

    // Check for negative index
//p    if (index < 0 ){
      index = index + length;
    }
    
    // Check for invalid index
//p    if(index >= length) {
        return -1; // or handle the error appropriately
    }

    // Removing the head node
//p    if (index == 0) {
        removedElem = node->value;
        l->head = node->next;
        node_free(node);
        return removedElem;
    }

    // Traverse the list to find the node at the given index
    while (node != NULL && counter < index) {
        prevNode = node;
        node = node->next;
        counter++;
    }

    // Remove the node
    if (node != NULL) {
        removedElem = node->value;
        prevNode->next = node->next;
        node_free(node);
        return removedElem;
    }

    // If the node wasn't found, return an error value
    return -1; 
}



bool list_is_in(list_t *l, elem value){
node_t *node = l->head; 

if (l == NULL){
  return false;
}

while(node != NULL){
  if(node->value == value){
    return true; 
  }
  node = node->next;
}
return false;
}

elem list_get_elem_at(list_t *l, int index){
//p  int length, counter = 0; 
  elem nValue = -1; 
  node_t *node;

  node = l->head;
  length = list_length(l);

//p  if(index > length || length == 0){ //handles out of bounds or empty lists
    return -1;
  }

//p  if(index < 0){          // if the index is negative, find its positive index
    index = index + length;
  }

  while(index <= length){
    if(index == counter){
      nValue = node->value;       //retrieve value at index of node
      return nValue;
    }
    node = node->next;
    counter++;
  }

  return nValue;
}

int list_get_index_of(list_t *l, elem value){
  int index, length;
  node_t *node;

  node = l->head; 
  length = list_length(l);
//p  index = 0;

//p  if(length == 0){
    return -1;
  }

  while(node->next != NULL){
    if(node->value == value){
      return index;       //returns index when found
    }
    node = node->next;
    index++;   
  }

  if (node->next = NULL){
    printf("not found");
  }

return -1;        //returns -1 if not found
}