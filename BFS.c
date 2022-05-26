#include<stdio.h>
#include<stdlib.h>

int v;

struct node{
  int data;
  struct node* link;
};
struct node* head=NULL;
struct node* tail=NULL;

void enqueue(int num){
    
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data=num;
    new_node->link=NULL;
  if(head==NULL){
    head=new_node;
    tail=new_node;
    
  }
  else{
    tail->link=new_node;
    tail=new_node;
    
  }
}

int dequeue(){
  if(head == NULL){
    printf("Queue is empty.");
    return -1;
  }
  else{
    struct node* temp = head;
    int num = head->data;
    head=head->link;
    free(temp);
    return num;
  }
}

void display(){
  
    struct node* temp = head;
  while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->link;
  }
  printf("\n");
}

void createGraph(int g[20][20]){
  int flag,e;
  printf("Enter 1 if undirected and 0 if directed : ");
  scanf("%d",&flag);

  printf("Enter the number of vertices : ");
  scanf("%d",&v);

  printf("Enter the number of edges : ");
  scanf("%d",&e);

  for(int i = 0; i < v; i++){
    for(int j = 0; j < v; j++){
    g[i][j]=0;
    }
    
  }

  for(int i = 0; i < e; i++){
    int v1,v2;
    printf("Enter the terminals of the edges(v1,v2) : ");
    scanf("%d %d",&v1,&v2);
    
    g[v1][v2]=1;
    if(flag==1){
    g[v2][v1]=1;
    }
  }
  }

  void displayGraph(int g[20][20]){
    for(int i = 0; i < v; i++){
    for(int j = 0; j < v; j++){
      printf("%d ",g[i][j]);
    }
    printf("\n");
  }
    printf("\n");
  }

void bfs(int g[20][20], int s){
  int vis[v];

  for(int i=0; i<v; i++){
    vis[i]=0;
  }
  printf("%d\t",s);
  vis[s]=1;
  enqueue(s);

  while(head != NULL){
    
    int num = dequeue();
    
    for(int i = 0; i < v; i++){
      
      if(g[num][i] == 1 && vis[i] == 0){
        printf("%d\t",i);
        vis[i]=1;
        enqueue(i);
      }
    }
  }
}

int main(){
  int g[20][20],source;
  createGraph(g);
  displayGraph(g);
  printf("Enter the source vertex for BFS Traversal : ");
  scanf("%d",&source);
  bfs(g,source);
  // enqueue(10);
  // enqueue(20);
  // enqueue(30);
  // enqueue(40);
  // enqueue(50);
  // enqueue(60);
  // display();
  // int z;
  // z = dequeue();
  // z = dequeue();
  // z = dequeue();
  // z = dequeue();
  // display();
  // printf("Head : %d\n",head->data);
  // printf("tail : %d\n",tail->data);
  return 0;
}
