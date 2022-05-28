#include<stdio.h>
#include<stdbool.h>
int v;

void createGraph(int g[20][20]){
int flag=0,e,v1,v2,cost;
printf("Enter 1 if graph is undirected, otherwise 0 : ");
scanf("%d",&flag);

printf("Enter the number of vertices in your graph : ");
scanf("%d",&v);

printf("Enter the number of edges in your graph : ");
scanf("%d",&e);

for(int i = 0; i < e; i++){
printf("Enter the edge terminals (v1 v2) : ");
scanf("%d %d", &v1,&v2);

printf("Enter the edge cost : ");
scanf("%d",&cost);

g[v1][v2] = cost;
if(flag == 1){
g[v2][v1] = cost;

}
}

}

void displayAdjacencyMatrix(int g[20][20]){
printf("\nThe Adjacency Matrix : \n\n");
for(int i = 0; i < v; i++){
    for(int j = 0; j < v; j++){
    printf("%d\t",g[i][j]);
    }
    printf("\n");
}
}

void primsAlgorithm(int g[20][20]){
printf("\n\nMinimum Cost Spanning Tree");
printf("\nEdge : Weight \n");

int numOfSelectedEdges = 0, selected[20]={},x,y,cost = 0;
selected[0]= true;


while(numOfSelectedEdges < v-1){
int min = 999;
x=0,y=0;

for(int i = 0; i < v; i++){
    if(selected[i]){
        for(int j = 0; j < v; j++){
            if((g[i][j] > 0) && !selected[j]){
                if(g[i][j] < min){
                    min = g[i][j];
                    x = i;
                    y = j;
                }
            }
        }
    }
}

printf("%d - %d : %d\n",x,y,min);
selected[y] = true;
cost+=g[x][y];
numOfSelectedEdges++;
}
printf("The Cost of Minimum Spanning Tree is %d",cost);
}
int main(){
    int g[20][20]={};
    createGraph(g);
    displayAdjacencyMatrix(g);
    primsAlgorithm(g);
    
    return 0;
}
