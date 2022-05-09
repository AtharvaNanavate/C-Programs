#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* left;
struct node* right;
};

struct node* newNode(int num){

struct node* temp = malloc(sizeof(struct node));
temp -> data = num;
temp -> left = NULL;
temp -> right = NULL;

return temp;
}

struct node* insertBST(struct node* root, int key){

  if(root == NULL){
    return newNode(key);
  }

  if(key > root->data){
    root->right = insertBST(root->right, key);
  }
  
  else if(key < root->data){
    root->left = insertBST(root->left, key);
  }
return root;
}

void inorder(struct node* root){
if(root != NULL){
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
}
}

int main(){
  struct node* root = NULL;

  root = newNode(50);
  insertBST(root,20);
  insertBST(root,60);
  insertBST(root,25);
  insertBST(root,55);
  insertBST(root,100);
  
  inorder(root);
  return 0;

}