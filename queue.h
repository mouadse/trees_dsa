#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
typedef struct s_node {
  int data;
  struct s_node *lChild;
  struct s_node *rChild;
} node;

typedef struct s_queue {
  int size;
  int front;
  int rear;
  node **Q;
} queue;

#endif // ! QUEUE
