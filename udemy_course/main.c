#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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

int main(void) {
  // code it here
  Insert(10);
  Insert(5);
  Insert(20);
  Insert(8);
  Insert(30);
  Inorder(root);

  Destroy(root);
  return (EXIT_SUCCESS);
}
