#include "queue_lifo.h"

void construct_lifo_queue(lifo_queue_t* lifo) {
	lifo->list = (linked_list_t*)malloc(sizeof(linked_list_t));
	construct_linked_list(lifo->list);
}
void destruct_lifo_queue(lifo_queue_t* lifo) {
	destruct_linked_list(lifo->list);
}
double front_lifo_queue(lifo_queue_t* lifo) {
	return lifo->list->head->data;
}
double back_lifo_queue(lifo_queue_t* lifo) {
	return lifo->list->tail->data;
}
bool empty_lifo_queue(lifo_queue_t* lifo) {

	if (lifo->list->size == 0) {
		return true;
	}
	else {
		return false;
	}
}
unsigned int size_lifo_queue(lifo_queue_t* lifo) {
	return lifo->list->size;
}
void push_lifo_queue(lifo_queue_t* lifo, double val) {
	push_front_linked_list(lifo->list, val);
}
void pop_lifo_queue(lifo_queue_t* lifo) {
	remove_node_linked_list(lifo->list, 0);
}
double pop_front_lifo_queue(lifo_queue_t* lifo) {
	double val = front_lifo_queue(lifo);
	pop_fifo_queue(lifo);
	return val;
}
void print_lifo_queue(lifo_queue_t* lifo) {
	print_linked_list(lifo->list);
}
