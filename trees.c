#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
  int val;
  struct s_node *right;
  struct s_node *left;
} node;

node *create_node(int val) {
  node *n = malloc(sizeof(node));
  if (!n)
    return (NULL);
  n->val = val;
  n->left = n->right = NULL;
  return (n);
}

node *insertNode(node *root, int val) {
  if (!root)
    root = create_node(val);
  else if (val < root->val)
    root->left = insertNode(root->left, val);
  else
    root->right = insertNode(root->right, val);
  return (root);
}

void inorder_printing(node *root) {
  if (root != NULL) {
    inorder_printing(root->left);
    printf("%d\n", root->val);
    inorder_printing(root->right);
  }
}

void free_tree(node *root) {
  if (root) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// time to implement pre order traversel

void preOrderTravers(void *root) {
  node *r = (node *)root;
  if (!r)
    return;
  printf("%d\n", r->val);
  preOrderTravers(r->left);
  preOrderTravers(r->right);
}

// Post order traversal now

void postOrdTraver(void *root) {
  if (!root)
    return;
  node *r = (node *)root;
  postOrdTraver(r->left);
  postOrdTraver(r->right);
  printf("%d\n", r->val);
}

// implement an interface to get the max node the one with max val

node *get_max(node *root) {
  if (root->right != NULL)
    return (get_max(root->right));
  return (root);
}

// Lets make a function to check if a val or key is present in our tree or !

int find_key(node *root, int val) {
  if (!root)
    return (0);
  else if (val < root->val)
    return (find_key(root->left, val));
  else if (val > root->val)
    return (find_key(root->right, val));
  else if (val == root->val)
    return (1);
  else {
    return (0);
  }
}

int main(void) {
  node *root = NULL;

  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 7);
  root = insertNode(root, 2);
  root = insertNode(root, 4);
  root = insertNode(root, 6);
  root = insertNode(root, 8);

  // printf("In order --> \n");
  // inorder_printing(root);
  //
  // printf("Pre order --> \n");
  // preOrderTravers(root);
  //
  // printf("Post order --> \n");
  // postOrdTraver(root);
  //
  // node *max_node = get_max(root);
  //
  // printf("The node with max val is \"%p\" and its val is >>> %d <<<\n",
  //        max_node, max_node->val);

  if (find_key(root, 7))
    printf("We found 7 in our tree\n");

  if (!find_key(root, 1337))
    printf("Let is not on the TREE\n");

  free_tree(root);
  return (EXIT_SUCCESS);
}
