#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_node {
  int data;
  struct s_node *leftChild;
  struct s_node *rightChild;
} node;

typedef struct s_tree {
  node *tree;
  int (*compare)(const void *key1, const void *key2);
  void (*destroy)(void *data);
} b_tree;

#endif
