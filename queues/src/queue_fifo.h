#ifndef QUEUE_FIFO_H_
#define QUEUE_FIFO_H_

#include "linked_list.h"
#include <stdbool.h>

typedef struct {
	linked_list_t* list;
} fifo_queue_t;

void construct_fifo_queue(fifo_queue_t*);
void destruct_fifo_queue(fifo_queue_t*);
double front_fifo_queue(fifo_queue_t*);
double back_fifo_queue(fifo_queue_t*);
bool empty_fifo_queue(fifo_queue_t*);
unsigned int size_fifo_queue(fifo_queue_t*);
void push_fifo_queue(fifo_queue_t*,double);
void pop_fifo_queue(fifo_queue_t*);
double pop_front_fifo_queue(fifo_queue_t*);
void print_fifo_queue(fifo_queue_t*);





#endif
