#include "queue_lifo.h"
#include <math.h>

int main(void) {
  lifo_queue_t q;
  construct_lifo_queue(&q);
  // Add elements to the queue
  for (unsigned int i = 0; i != 5; ++i) push_lifo_queue(&q, i*3.14/2);
  print_lifo_queue(&q);

  // Pop the queue
  printf("queue size is %u\n", size_lifo_queue(&q));
  while (!empty_lifo_queue(&q)) {
    double val = pop_front_lifo_queue(&q);
    printf("popped value %f\n", val);
    printf("\tqueue size is now %u\n", size_lifo_queue(&q));
  }

  destruct_lifo_queue(&q);
}
