#ifndef QUEUE_LIFO_H_
#define QUEUE_LIFO_H_

#include "linked_list.h"
#include <stdbool.h>

typedef struct {
	linked_list_t* list;
} lifo_queue_t;

void construct_lifo_queue(lifo_queue_t*);
void destruct_lifo_queue(lifo_queue_t*);
double front_lifo_queue(lifo_queue_t*);
double back_lifo_queue(lifo_queue_t*);
bool empty_lifo_queue(lifo_queue_t*);
unsigned int size_lifo_queue(lifo_queue_t*);
void push_lifo_queue(lifo_queue_t*, double);
void pop_lifo_queue(lifo_queue_t*);
double pop_front_lifo_queue(lifo_queue_t*);
void print_lifo_queue(lifo_queue_t*);

#endif
