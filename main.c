#include <stdio.h>

#include "list.h"

int main(int argc, char *argv[]) {

  printf("Link List Testing...\n");  
  list_t* my_list;
  my_list = list_alloc();

  printf("\nPointer |%p \n", my_list);   //test implementation
  int length = list_length(my_list);   
  printf("List Length | %d\n", length);
  //space allocated ? check :/

  printf("\nCreating List Testing...\n"); 

  list_add_to_front(my_list,9);  //list: 9 
  list_add_to_front(my_list,8);  //list: 8 9 
  list_add_to_front(my_list,7);  //list: 7 8 9 
  list_add_to_front(my_list,6);  //list: 6 7 8 9 

  list_print(my_list);

  printf("\nAdding At Index Testing...\n"); 

  list_add_at_index(my_list, 4, 2);  //list: 6 7 8 4 9 
  list_add_at_index(my_list, 10, 3); //list: 6 7 8 4 10 9 
  list_add_at_index(my_list, 1, 0);  //list: 1 6 7 8 4 10 9 

  list_print(my_list); 

  printf("\nAdding To Back Testing...\n"); 

  list_add_to_back(my_list,2);  //list: 1 6 7 8 4 10 9 2
  list_add_to_back(my_list,7);  //list: 1 6 7 8 4 10 9 2 7
  list_add_to_back(my_list,8);  //list: 1 6 7 8 4 10 9 2 7 8 
  list_add_to_back(my_list, 11);  //list: 1 6 7 8 4 10 9 2 7 8 0
  
  list_print(my_list);

  printf("\nRemoving Elements from Front List...\n");

  list_remove_from_front(my_list);  //list: 6 7 8 4 10 9 2 7 8 0
  list_remove_from_front(my_list);  //list: 7 8 4 10 9 2 7 8 0

  list_print(my_list);
  
  printf("List Length | %d\n", list_length(my_list));

  printf("\nRemoving Elements from Back List...\n");

  elem removal1 = list_remove_from_back(my_list); //list: 1 6 7 8 4 10 9 2 7 8 3
  elem removal2 = list_remove_from_back(my_list); //list: 1 6 7 8 4 10 9 2 7 

  printf("\n%d and %d has been removed from the list!\n", removal1, removal2);

  list_print(my_list);
  
  printf("New List Length | %d\n", list_length(my_list));

  printf("\nElement Is In List Testing...\n\n");

  /** put it in a function **/ 
  bool isInTestOne = list_is_in(my_list, 7);
  bool isInTestTwo = list_is_in(my_list, 9);
  bool isInTestThree = list_is_in(my_list, 1);
if (isInTestOne == true)
  printf("It was in the list!\n");
else
  printf("It was not in the list!\n");
if (isInTestTwo == true)
  printf("It was in the list!\n");
else
  printf("It was not in the list!\n");
if (isInTestThree == true)
  printf("It was in the list!\n");
else
  printf("It was not in the list!\n");

  list_print(my_list);

  printf("\nGet Element At Testing...\n");
  list_print(my_list);

  elem index4 = list_get_elem_at(my_list, 4);
  elem index2 = list_get_elem_at(my_list, 2);

  printf("The elem at index 4 is %d and at 2 is %d.\n", index4, index2);
  
  int listIndexTest1 = list_get_index_of(my_list, 10);

  list_print(my_list);
  
  printf("\n10 has an index of %d! \n", listIndexTest1);

  elem indexRemoval1 = list_remove_at_index(my_list, 0);
  elem indexRemoval2 = list_remove_at_index(my_list, 4);

  printf("The elem at index 0 is %d and was removed!\nThe elem at index 4 is %d and was removed!\n", indexRemoval1, indexRemoval2);
 
  list_print(my_list);
  printf("Freeing UP Some Space...\n"); 
  list_free(my_list); 
  printf("List Length | %d\n", length);

  return 0;
}
