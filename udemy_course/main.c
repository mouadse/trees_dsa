#include <stdio.h>
#include <stdlib.h>
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

int main(void) {
  // code it here
  return (EXIT_SUCCESS);
}
