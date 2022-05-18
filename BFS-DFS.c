#include<stdio.h>

void createGraph(int g[20][20]){
  int flag=0,edges,vertices,v1,v2;
  
  printf("Enter 1 if the graph is undirected and 0 if graph is directed : ");
  scanf("%d",&flag);

  printf("Enter the number of vertices in your graph : ");
  scanf("%d",&vertices);

  printf("Enter the number of edges in your graph : ");
  scanf("%d",&edges);

  for(int i = 0; i < vertices; i++){
    for(int j = 0; j < vertices; j++){
      g[i][j]=0;
  }
  
}

  for(int i = 0; i < edges; i++){
    
    printf("Enter the edge terminals : ");
    scanf("%d %d",&v1,&v2);
    
    g[v1][v2] = 1;
    
    if(flag == 1){
    g[v2][v1] = 1;
    }

  }

}

void displayGraph(int g[20][20], int n){
  printf("The adjacency matrix is : \n");

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ",g[i][j]);
  }
  printf("\n");
}
}
int main(){
  int g[20][20];
  createGraph(g);
  displayGraph(g,5);
  return 0;
}
