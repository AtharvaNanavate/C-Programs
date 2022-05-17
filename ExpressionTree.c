#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node{
  char data;
  struct node* left;
  struct node* right;
  struct node* next;
};
struct node* top = NULL;

void push(char ch){
  struct node* new_node = malloc(sizeof(struct node));
  new_node->data=ch;
  new_node->left=NULL;
  new_node->right=NULL;
  new_node->next=top;
  top=new_node;
}

void pop(){
  if(top == NULL){
    printf("Stack is empty.");
  }
  else{
  struct node* temp;
  temp = top;
  top=top->next;
  free(temp);
  }
}

void display(){
  struct node* temp;
  temp=top;
  while(temp != NULL){
    printf("%c\n",temp->data);
    temp = temp->next;
  }
    printf("\n");
}

void postfixExp(){
  top=NULL;
  char str[20];
  printf("Enter the Postfix Expression : ");
  scanf("%s",str);

  for(int i = 0; str[i] != '\0'; i++){
    
    if(isalpha(str[i])){
      push(str[i]);
    }
    else{
      struct node* opNode = malloc(sizeof(struct node));
      struct node* leftNode = malloc(sizeof(struct node));
      struct node* rightNode = malloc(sizeof(struct node));
      opNode->data = str[i];
      
      rightNode->data=top->data;
      rightNode->right=top->right;
      rightNode->left=top->left;
      opNode->right = rightNode;
      pop();

      leftNode->data=top->data;
      leftNode->right=top->right;
      leftNode->left=top->left;
      opNode->left = leftNode;
      pop();
      opNode->next = top;
      top = opNode;
    }
  }
  
}

void prefixExp(){
  top=NULL;
  char str[20];
  printf("Enter the Prefix Expression : ");
  scanf("%s",str);
  int l = strlen(str);
  for(int i = l-1; i >= 0; i--){
    
    if(isalpha(str[i])){
      push(str[i]);
    }
    else{
      struct node* opNode = malloc(sizeof(struct node));
      struct node* leftNode = malloc(sizeof(struct node));
      struct node* rightNode = malloc(sizeof(struct node));
      
      opNode->data = str[i];
    
      leftNode->data=top->data;
      leftNode->right=top->right;
      leftNode->left=top->left;
      opNode->left = leftNode;
      pop();

      rightNode->data=top->data;
      rightNode->right=top->right;
      rightNode->left=top->left;
      opNode->right = rightNode;
      pop();

      opNode->next = top;
      top = opNode;
    }
  }
  
}
void inorder(struct node* top){
  if(top != NULL){
    inorder(top->left);
    printf("%c ",top->data);
    inorder(top->right);
  }
}

int main(){
  
  postfixExp();
  inorder(top);

  prefixExp();
  inorder(top);

  return 0;
}
