#include "queue_fifo.h"
#include <math.h>

int main(void) {
  fifo_queue_t q;
  construct_fifo_queue(&q);
  // Add elements to the queue
  for (unsigned int i = 0; i != 5; ++i) push_fifo_queue(&q, i*3.1415/2);
  print_fifo_queue(&q);

  // Pop the queue
  printf("queue size is %u\n", size_fifo_queue(&q));
  while (!empty_fifo_queue(&q)) {
    double val = pop_front_fifo_queue(&q);
    printf("popped value %f\n", val);
    printf("\tqueue size is now %u\n", size_fifo_queue(&q));
  }

  destruct_fifo_queue(&q);
}
