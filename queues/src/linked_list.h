#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node_t node_t;

struct node_t {
  double data;
  node_t* next;
  node_t* prev;
};

typedef struct {
  node_t *head, *tail;
  unsigned int size;
} linked_list_t;

// Function to create a blank linked-list
void construct_linked_list(linked_list_t*);
// Function to destruct a linked-list
void destruct_linked_list(linked_list_t*);
// Function to 'push_back' a node storing a given double value
void push_back_linked_list(linked_list_t*, double);
// Function to 'push_front' a node storing a given double value
void push_front_linked_list(linked_list_t*, double);
// Function to remove a node at a given index
void remove_node_linked_list(linked_list_t*, unsigned int);
// Function to add a node at a given index
void add_node_linked_list(linked_list_t*, unsigned int, double);
// Function to incriment pointer to node either towards 'next' or 'prev'
typedef enum { NEXT, PREV } node_iter_dir_t;
void incriment_node_pointer(node_t**, node_iter_dir_t, unsigned int);
// Function to find a node at a given index
void find_node_linked_list(linked_list_t*, node_t**, unsigned int);

// Function to print a linked list
void print_linked_list(linked_list_t*);
void print_node(node_t*);

#endif
