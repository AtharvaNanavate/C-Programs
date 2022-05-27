#include <stdio.h>
#include <stdlib.h>

int v;

struct node
{
  int data;
  struct node *next;
};
struct node *top = NULL;

void push(int num)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->data = num;

  if (top == NULL)
  {
    top = temp;
    temp->next = NULL;
  }

  else
  {
    struct node *temp1 = top;
    top = temp;
    temp->next = temp1;
  }
}

int pop()
{
  if (top == NULL)
  {
    printf("Stack is empty.");
    return -1;
  }
  else
  {
    struct node *temp = top;
    int num = top->data;
    top = top->next;
    free(temp);
    return num;
  }
}

void display()
{
  if (top == NULL)
  {
    printf("Stack is empty.");
  }
  else
  {
    struct node *temp = top;
    while (temp != NULL)
    {
      printf("%d\t", temp->data);
      temp = temp->next;
    }
  }
  printf("\n");
}

void createGraph(int g[20][20])
{
  int v1, v2, e, flag = 0;
  printf("Enter 1 if graph is undirected and 0 if graph is directed : ");
  scanf("%d", &flag);

  printf("Enter the number of vertices in the graph : ");
  scanf("%d", &v);
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      g[i][j] = 0;
    }
  }
  printf("Enter the number of edges in the graph : ");
  scanf("%d", &e);

  printf("Enter the details of edges :\n\n");

  for (int i = 0; i < e; i++)
  {

    printf("Enter the terminal vertices of the edge (v1 v2) : ");
    scanf("%d %d", &v1, &v2);
    g[v1][v2] = 1;
    if (flag == 1)
    {
      g[v2][v1] = 1;
    }
  }
}

void displayAdjacencyMatrix(int g[20][20])
{

  printf("\n\nThe Adjacency Matrix : \n\n");

  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      printf("%d ", g[i][j]);
    }
    printf("\n");
  }
}

void dfs(int g[20][20], int s)
{
  int vis[v], num;
  for (int i = 0; i < v; i++)
  {
    vis[i] = 0;
  }
  printf("%d\t", s);
  vis[s] = 1;
  push(s);
  while (top != NULL)
  {
    num = pop();
    if (vis[num] == 0)
    {
      vis[num] = 1;
      printf("%d\t", num);
    }

    for (int i = 0; i < v; i++)
    {
      if (g[num][i] == 1 && vis[i] == 0)
      {
        push(i);
      }
    }
  }
}
// for(int j = 0; j < v; j++){

int main()
{
  int g[20][20], source;
  createGraph(g);
  displayAdjacencyMatrix(g);

  printf("Enter the source vertex for DFS Traversal : ");
  scanf("%d", &source);

  dfs(g, source);

  // push(10);
  // push(20);
  // push(30);
  // push(40);
  // push(50);
  // display();
  // pop();
  // display();
  // push(50);
  // display();
  return 0;
}
