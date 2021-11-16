## ECE 275 Homework 3: Queues

Homework 3 will focus on creating both a LIFO and FIFO queue using a provided implementation of a doubly linked list. Many data structures are simply extensions of other data structures, e.g., the C++ STL `std::queue` and `std::stack` are both "container adapters" which manipulate an underlying linked list to implement a FIFO or LIFO queue, respectively. 


## Program Requirements
* All work will be done in the C programming language and *not* C++. Note that this assignment assumes no C knowledge outside of what you know given work done in this class so far. 
* You **shall** define both a LIFO and FIFO queue as types `lifo_queue_t` and `fifo_queue_t` respectively
* Each queue type *should* adapt the `linked_list_t` type provided by the instructor. 

## Types to Define
Define the LIFO queue as

```
typedef struct {
  linked_list_t* list;
} lifo_queue_t;
```

and the FIFO queue as 

```
typedef struct {
  linked_list_t* list;
} fifo_queue_t;
```

Observe that both the LIFO and FIFO queue, in this case, are simply a struct holding a pointer to the linked-list type which is given. Note that this is a C-style struct declaration. 

## Functions to Define
For each type of queue, define the below functions. Note that function names below should add a trailing identifier for which queue type, e.g., `front` should be `front_lifo_queue` for the LIFO queue type and `front_fifo_queue` for the FIFO queue type. Note that type `QT` in this section will refer to both `lifo_queue_t` and `fifo_queue_t` herein. 

* `construct`:
	* Returns type `void`
	* Accepts argument of type `QT*`
	* Constructs the queue type. (Hint: this function should allocate memory for the internal linked list and call the constructor function for the linked list)
* `destruct`:
	* Returns type `void`
	* Accepts argument of type `QT*`
	* Destructs the queue type. (Hint: this function should call the destructor for the internal linked list and release the dynamically allocated memory in the constructor)
* `front`:
	* Returns type `double`	
	* Accepts argument of type `QT*`
	* Should return the element at the top of the queue, i.e., the first element out of the queue
* `back`:
	* Returns type `double`
	* Accepts argument of type `QT*`
	* Should return the element at the back of the queue, i.e., the last element out of the queue
* `empty`:
	* Returns type `bool`
	* Accepts argument of type `QT*`
	* Returns true if the queue is empty else false
* `size`:
	* Returns type `unsigned int`
	* Accepts argument of type `QT*`
	* Returns the size of the queue (HINT: this it the size of the underlying linked list)
* `push`:
	* Returns type `void`
	* Accepts types `QT*` and `double` where the `double`-typed value is the value to be added to the queue
	* Adds an element of type double to the queue
* `pop`:
	* Returns type `void`
	* Accepts argument of type `QT*`
	* Removes the element at the front of the queue and decreases the queue's size by 1
* `pop_front`:
	* Returns type `double`
	* Accepts argument of type `QT*`
	* Returns the element at the front of the queue and removes that element from the queue (HINT: call `front` and `pop` functions and return the result of the call to `front`)

Declare each function in the proper header file, e.g., `src/queue_fifo.h`, and provide implementations in the associated source file, e.g., `src/queue_fifo.c`. Example main functions have been provided for your convenience which exercise some of the queue methods. 

### Linked List Class
The following methods are available to you via an instructor-defined implementation of a doubly linked list. Please use these functions to effectuate your queue functions. 

```
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
// Function to increment pointer to node either towards 'next' or 'prev'
typedef enum { NEXT, PREV } node_iter_dir_t;
void incriment_node_pointer(node_t**, node_iter_dir_t, unsigned int);
// Function to find a node at a given index
void find_node_linked_list(linked_list_t*, node_t**, unsigned int);

// Function to print a linked list
void print_linked_list(linked_list_t*);
void print_node(node_t*);
```
Note that some of these functions are helper functions, e.g., `find_node_linked_list`. The instructor's solution utilizes the `push_front` and `push_back` functions along with `remove_node` to manipulate the queue. 

Note that data is stored at each node as such:

```
struct node_t {
  double data;
  node_t* next;
  node_t* prev;
};
```
I.e., data is stored at `node_t::data` (HINT: You'll need to access the data of either the head of the tail, depending on how you construct your queue, to perform the `front` and `back` functions. 
	
## Testing
The `lifo_queue_t` will be tested against the `std::stack` C++ STL class and the `fifo_queue_t` will be tested against the `std::queue` C++ STL class. Each queue will be randomly initialized with a random number of values and then "popped" until empty. 

Tests are run in GitLab as normal and your score will be output as normal via the GitLab test artifacts. 

No program output will be considered so feel free to implement log messages as required. 

Tester code is available on D2L under the Assignment for this Homework. 