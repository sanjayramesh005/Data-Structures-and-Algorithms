#include <stdio.h>
#include <stdlib.h>

typedef struct node{//Node for both lists and the tree.
  int value;
  struct node *small;
  struct node *large;
} node;

node* make_node(int value){//creates a new node and returns the pointer to it.
  node* x;
  x = (node*)malloc(sizeof(node));
  x->value = value;
  x->small = NULL;
  x->large = NULL;
  return x;
}

void insert_node(int n, node** rootref){//inserts a node with a value n to the given tree.
  node* root = *rootref;
  if (root == NULL) *rootref = make_node(n);
  else{
    if (n <= root->value) insert_node(n, &(root->small));
    else insert_node(n, &(root->large));
  }
}

node* JoinList(node* root1, node* root2){//Joins two circular lists with heads root1 and root2 and returns the head to the resulting list.
  if (root1==NULL) return root2;
  if (root2==NULL) return root1;
  node* tmp = root2->small;
  (root1->small)->large = root2;
  root2->small = root1->small;
  tmp->large = root1;
  root1->small = tmp;
  return root1;
}

node* TreeToList(node* root){//Given a tree this function converts it to a circular list.
  if (root == NULL){
    return NULL;
  }
  else{
    node* s = TreeToList(root->small);
    node* t = TreeToList(root->large);
    root->small = root;
    root->large = root;
    s = JoinList(s,root);
    s = JoinList(s,t);
    return s;
  }
}

void print_list(node* head){//printing a circular list. This can very well print other lists too.
  node* current = head;
  while(current!=NULL){
    printf ("%d ", current->value);
    current = current->large;
    if (current==head) break;
  }
  printf ("\n");
}

int main(){// demo
  node* root = NULL;
  node* head;

  insert_node(4, &root);
  insert_node(2, &root);
  insert_node(1, &root);
  insert_node(3, &root);
  insert_node(5, &root);

  head = TreeToList(root);

  print_list(head);
  
  return 0;
}
