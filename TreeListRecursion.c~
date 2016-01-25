#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *small;
  struct node *large;
} node;

node* make_node(int value){
  node* x;
  x = (node*)malloc(sizeof(node));
  x->value = value;
  x->small = NULL;
  x->large = NULL;
  return x;
}

void insert_node(int n, node** rootref){
  node* root = *rootref;
  if (root == NULL) *rootref = make_node(n);
  else{
    if (n <= root->value) insert_node(n, &(root->small));
    else insert_node(n, &(root->large));
  }
}

node* JoinList(node* root1, node* root2){
  if (root1==NULL) return root2;
  if (root2==NULL) return root1;
  node* tmp = root2->small;
  (root1->small)->large = root2;
  root2->small = root1->small;
  tmp->large = root1;
  root1->small = tmp;
  return root1;
}

node* TreeToList(node* root){
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

void print_list(node* head){
  node* current = head;
  while(current!=NULL){
    printf ("%d ", current->value);
    current = current->large;
    if (current==head) break;
  }
  printf ("\n");
}

int main(){
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
