#include "linked_list.h"


void construct_linked_list(linked_list_t* list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void destruct_linked_list(linked_list_t* list) {
  node_t* thisNode = list->head;
  while(thisNode) {
    node_t* next = thisNode->next;
    free(thisNode);
    thisNode = next;
  }
}

void push_back_linked_list(linked_list_t* list, double val_in) {
    if (list->head) {
        list->tail->next = (node_t*)malloc(sizeof(node_t));
        list->tail->next->prev = list->tail;
        list->tail = list->tail->next;
        list->tail->data = val_in;
        list->tail->next = NULL;
    }
    else {
        list->head = (node_t*)malloc(sizeof(node_t));
        list->head->next = NULL;
        list->head->prev = NULL;
        list->tail = list->head;
        list->head->data = val_in;
    }
    ++list->size;
}

void push_front_linked_list(linked_list_t* list, double val_in) {
  if (!list->head) {
    list->head = (node_t*)malloc(sizeof(node_t));
    list->head->data = val_in;
    list->head->next = NULL;
    list->head->prev = NULL;
    list->tail = list->head;
  }
  else {
    node_t* currHead = list->head;
    list->head = (node_t*)malloc(sizeof(node_t));
    list->head->data = val_in;
    list->head->next = currHead;
    list->head->prev = NULL;
    currHead->prev = list->head;
  }
  ++list->size;
}

void remove_node_linked_list(linked_list_t* list, unsigned int idx) {
  // Check if we're removing the head or the tail
  if (idx == 0) {
    node_t* newHead = list->head->next;
    free(list->head);
    list->head = NULL;
    if (newHead) {
      list->head = newHead;
      list->head->prev = NULL;
    }
  }
  else if (idx == list->size-1) {
    node_t* newTail = list->tail->prev;
    free(list->tail);
    list->tail = NULL;
    if (newTail) {
      list->tail = newTail;
      list->tail->next = NULL;
    }
  }
  else {
    node_t *node_to_remove, *node_before, *node_after;
    find_node_linked_list(list, &node_to_remove, idx);
    node_before = node_to_remove->prev;
    node_after = node_to_remove->next;
    free(node_to_remove);
    node_before->next = node_after;
    node_after->prev = node_before;
  }
  --list->size;
}

void add_node_linked_list(linked_list_t* list, unsigned int idx, double val) {
  // Make sure that the index is not the first or the last
  assert(idx != 0 && idx != list->size-1);
  node_t *curr_idx, *curr_prev;
  find_node_linked_list(list, &curr_idx, idx);
  curr_prev = curr_idx->prev;
  curr_prev->next = (node_t*)malloc(sizeof(node_t));
  curr_prev->next->data = val;
  curr_prev->next->next = curr_idx;
  curr_idx->prev = curr_prev->next;
  ++list->size;
}

void find_node_linked_list(linked_list_t* list, node_t** node, unsigned int idx) {
  node_t* tmp;
  node_iter_dir_t dir;
  unsigned int num_iters_required;
  if (idx < list->size/2) { // then start at the head and go towards the tail
    tmp = list->head;
    dir = NEXT;
    num_iters_required = idx;
    //printf("Looking from the head for index %u will iterate %u times\n", idx, num_iters_required);
  }
  else { // then start at the tail and go towards the head
    tmp = list->tail;
    dir = PREV;
    num_iters_required = list->size - 1 - idx;
  }
  // Find the node to remove via the iterator function
  incriment_node_pointer(&tmp, dir, num_iters_required);
  *node = tmp;
  //printf("Found node at idx %u with data %f\n", idx, tmp->data);
}

void incriment_node_pointer(node_t** node_p, node_iter_dir_t dir, unsigned int N) {
  unsigned int i = 0;
  node_t* tmp = *node_p;
  while (i != N) {
    if (dir == NEXT) tmp = tmp->next;
    else tmp = tmp->prev;
    ++i;
  }
  *node_p = tmp;
}

void print_linked_list(linked_list_t* list) {
  node_t* thisNode = list->head;
  unsigned int idx = 0;
  // Loop until 'thisNode' is NULL
  while(thisNode) {
    print_node(thisNode);
    printf("\tIndex: %u\n", idx++);
    printf("\tIs head?: %u\n", thisNode == list->head);
    printf("\tIs tail?: %u\n", thisNode == list->tail);
    thisNode = thisNode->next;
  }
}

void print_node(node_t* node) {
  printf("Memory Location: %p\n", node);
  printf("\tData: %f\n", node->data);
  printf("\tNext Memory Loc.: %p\n", node->next);
  printf("\tPrev Memory Loc.: %p\n", node->prev);
}
