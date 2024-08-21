#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <unistd.h>

typedef struct t_node {
  int data;
  struct t_node *rchild;
  struct t_node *lchild;
} node;

node *root = NULL;

void Insert(int data) {
  node *t = root;
  node *r;
  node *p;

  if (root == NULL) {
    p = malloc(sizeof(node));
    p->data = data;
    p->lchild = p->rchild = NULL;
    root = p;
    return;
  }
  while (t != NULL) {
    r = t;
    if (data < t->data)
      t = t->lchild;
    else if (data > t->data)
      t = t->rchild;
    else {
      return;
    }
  }
  p = malloc(sizeof(node));

  p->data = data;
  p->lchild = p->rchild = NULL;

  if (data < r->data)
    r->lchild = p;
  else {
    r->rchild = p;
  }
}

void Inorder(node *p) {
  if (p != NULL) {
    // left -> root -> right
    Inorder(p->lchild);
    printf("%d\n", p->data);
    Inorder(p->rchild);
  }
}

node *Search(int key) {
  node *tmp = root;
  while (tmp != NULL) {
    if (key == tmp->data)
      return (tmp);
    else if (key < tmp->data)
      tmp = tmp->lchild;
    else {
      tmp = tmp->rchild;
    }
  }
  return ((void *)0);
}

void Destroy(node *p) {
  if (p) {
    Destroy(p->lchild);
    Destroy(p->rchild);
    free(p);
  }
}

node *RecursiveInsert(node *p, int data) {
  node *tmp = NULL;
  if (p == NULL) {
    tmp = malloc(sizeof(node));
    tmp->data = data;
    tmp->lchild = tmp->rchild = NULL;
    return (tmp);
  }
  if (data < p->data)
    p->lchild = RecursiveInsert(p->lchild, data);
  else if (data > p->data)
    p->rchild = RecursiveInsert(p->rchild, data);
  return (p);
}

// adding delete node funtions to our code

node *Delete(node *p, int key) {
  node *tmp;
  if (p == NULL)
    return (NULL);

  if (key < p->data)
    p->lchild = Delete(p->lchild, key);
  else if (key > p->data)
    p->rchild = Delete(p->rchild, key);
  else {
    // Case 1: Node with only one child or no child !!!
    if (p->lchild == NULL) {
      tmp = p->rchild;
      free(p);
      p = NULL;
      return (tmp);
    } else if (p->rchild == NULL) {
      tmp = p->lchild;
      free(p);
      return (tmp);
    }
    // Case 2: Node with two children
    // Find the in-order successor (Smallest in the right subtree)
    tmp = p->rchild;
    while (tmp && tmp->lchild != NULL) {
      tmp = tmp->lchild;
    }
    p->data = tmp->data;

    // time to delete the in-order successor
    p->rchild = Delete(p->rchild, tmp->data);
  }

  return (p);
}

// Function to count the num of nodes in our tree

int node_count(node *ptr) {
  int x, y;
  if (ptr != NULL) {
    x = node_count(ptr->lchild);
    y = node_count(ptr->rchild);
    return (x + y + 1);
  }
  return (0);
}

int main(void) {
  // code it here
  // Insert(10);
  // Insert(5);
  // Insert(20);
  // Insert(8);
  // Insert(30);
  root = RecursiveInsert(root, 10);
  RecursiveInsert(root, 5);
  RecursiveInsert(root, 20);
  RecursiveInsert(root, 8);
  RecursiveInsert(root, 30);
  Inorder(root);

  if (Search(5))
    printf("The node is found!!!\n");
  else
    printf("Node not found!!!\n");

  printf("The num of nodes in our tree before del is %d\n", node_count(root));
  Delete(root, 5);

  printf("The num of nodes in our tree after del is %d\n", node_count(root));
  Destroy(root);
  return (EXIT_SUCCESS);
}
