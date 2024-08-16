#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
  int data;
  struct s_node *leftChild;
  struct s_node *rightChild;
} node;

// Interface for creating a new node

node *create_node(int value) {
  node *n = malloc(sizeof(node));
  if (!n)
    return (NULL);
  n->rightChild = n->leftChild = NULL;
  n->data = value;
  return (n);
}

int main(void) {
  // code goes here
  return (EXIT_SUCCESS);
}
