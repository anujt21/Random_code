#include "linked_list.h"
#include <math.h>

void print_divider(void) {
  for (unsigned int i = 0; i != 35; ++i) printf("=");
  printf("\n");
}

void print_linked_list_divided(linked_list_t* list) {
  print_divider();
  print_linked_list(list);
  print_divider();
}

int main(void) {
  linked_list_t list;
  construct_linked_list(&list);

  // Make the list by push_back
  for (unsigned int i = 0; i != 5; ++i) push_back_linked_list(&list, M_PI*i);
  print_linked_list_divided(&list);
  // Remove an element from the list
  remove_node_linked_list(&list, 3);
  print_linked_list_divided(&list);
  // Add an element to the list
  add_node_linked_list(&list, 1, 12.34);
  print_linked_list_divided(&list);
  // push_front a list
  push_front_linked_list(&list, 69.420);
  print_linked_list_divided(&list);

  destruct_linked_list(&list);

  return 0;
}
