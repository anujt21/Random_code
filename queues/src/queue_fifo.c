#include "queue_fifo.h"


void construct_fifo_queue(fifo_queue_t* fifo) {
	fifo->list = (linked_list_t*)malloc(sizeof(linked_list_t));
	construct_linked_list(fifo->list);
}
void destruct_fifo_queue(fifo_queue_t* fifo) {
	destruct_linked_list(fifo->list);
}
double front_fifo_queue(fifo_queue_t* fifo) {
	return fifo->list->head->data;
}
double back_fifo_queue(fifo_queue_t* fifo) {
	return fifo->list->tail->data;
}
bool empty_fifo_queue(fifo_queue_t* fifo) {
	
	if (fifo->list->size == 0) {
		return true;
	}
	else {
		return false;
	}
}
unsigned int size_fifo_queue(fifo_queue_t* fifo) {
	return fifo->list->size;
}
void push_fifo_queue(fifo_queue_t* fifo, double val) {
	push_back_linked_list(fifo->list, val);
}
void pop_fifo_queue(fifo_queue_t* fifo) {
	remove_node_linked_list(fifo->list, 0);
}
double pop_front_fifo_queue(fifo_queue_t* fifo) {
	double val = front_fifo_queue(fifo);
	pop_fifo_queue(fifo);
	return val;
}
void print_fifo_queue(fifo_queue_t* fifo) {
	print_linked_list(fifo->list);
}

