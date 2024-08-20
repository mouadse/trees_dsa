#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_node {
  int data;
  struct t_node *rchild;
  struct t_node *lchild;
} node;

node *root = NULL;

int main(void) {
  // code it here
  return (EXIT_SUCCESS);
}
