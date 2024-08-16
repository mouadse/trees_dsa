#include "queue.h"
#include <stdio.h>
// Queue implementation
void create_queue(queue *q, int size) {
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (node **)malloc(size * sizeof(node *));
  if (!q->Q) {
    printf("Memory Error\n");
    exit(1);
  }
}

void enqueue(queue *q, node *x) {
  if ((q->rear + 1) % q->size == q->front) {
    printf("Queue is Full\n");
  } else {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

int isEmpty(queue q) { return q.front == q.rear; }

node *dequeue(queue *q) {
  node *x = NULL;
  if (isEmpty(*q)) {
    printf("Queue is Empty\n");
  } else {
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}

// Now let us implement the trees dsa using the queue

node *root = NULL;

void create_tree(void) {
  node *p, *t;
  int x;
  queue q;
  create_queue(&q, 100);
  printf("Enter root value ");
  scanf("%d", &x);
  root = (node *)malloc(sizeof(node));
  root->data = x;
  root->lChild = root->rChild = NULL;
  enqueue(&q, root);
  while (!isEmpty(q)) {
    p = dequeue(&q);
    printf("Enter left child of %d ", p->data);
    scanf("%d", &x);
    if (x != -1) {
      t = (node *)malloc(sizeof(node));
      t->data = x;
      t->lChild = t->rChild = NULL;
      p->lChild = t;
      enqueue(&q, t);
    }
    printf("Enter right child of %d ", p->data);
    scanf("%d", &x);
    if (x != -1) {
      t = (node *)malloc(sizeof(node));
      t->data = x;
      t->lChild = t->rChild = NULL;
      p->rChild = t;
      enqueue(&q, t);
    }
  }
}

void preorder(node *p) {
  if (p) {
    printf("%d ", p->data);
    preorder(p->lChild);
    preorder(p->rChild);
  }
}

void inorder(node *p) {
  if (p) {
    inorder(p->lChild);
    printf("%d ", p->data);
    inorder(p->rChild);
  }
}

void postorder(node *p) {
  if (p) {
    postorder(p->lChild);
    postorder(p->rChild);
    printf("%d ", p->data);
  }
}

void levelorder(node *root) {
  queue q;
  create_queue(&q, 100);
  printf("%d ", root->data);
  enqueue(&q, root);
  while (!isEmpty(q)) {
    root = dequeue(&q);
    if (root->lChild) {
      printf("%d ", root->lChild->data);
      enqueue(&q, root->lChild);
    }
    if (root->rChild) {
      printf("%d ", root->rChild->data);
      enqueue(&q, root->rChild);
    }
  }
}

int main() {
  create_tree();
  printf("Preorder: ");
  preorder(root);
  printf("\nInorder: ");
  inorder(root);
  printf("\nPostorder: ");
  postorder(root);
  printf("\nLevelorder: ");
  levelorder(root);
  printf("\n");
  return 0;
}
