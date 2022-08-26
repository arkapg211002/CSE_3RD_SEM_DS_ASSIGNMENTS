/*Write a program to implement DFS in C*/
#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define visited 2
#define finished 3
void create_graph(int **adj,int *n);
void DF_Traversal(int **adj,int *state,int *n);
void DFS(int **adj,int *state,int *n,int v);
void display_graph(int **adj,int *n);

void main()
{
    int n,**adj,*state,i,j;
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    adj=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        adj[i]=(int*)malloc(n*sizeof(int));
    }
    state=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            adj[i][j]=0;
        }
    }
    create_graph(adj,&n);
    printf("\nThe Graph is: \n");
    display_graph(adj,&n);
    printf("\nThe DFS Traversal is: \n");
    DF_Traversal(adj,state,&n);
}

void DF_Traversal(int **adj,int *state,int *n)
{
    int i,j,v;
    for(i=0;i<*n;i++)
    {
        state[i]=initial;
    }
    printf("Enter Start Vertex for DFS: \n");
    scanf("%d", &v);
    DFS(adj,state,n,v);
    for(i=0;i<*n;i++)
    {
        if(state[i]==initial)
        {
            DFS(adj,state,n,i);
        }
    }
}

void DFS(int **adj,int *state,int *n,int v)
{
    int i;
    state[v]=visited;
    printf("%d ",v);
    for(i=0;i<*n;i++)
    {
        if(adj[v][i]==1 && state[i]==initial)
        {
            DFS(adj,state,n,i);
        }
    }
    state[v]=finished;
}

void create_graph(int **adj,int *n)
{
    int count,max_edge,origin,destin,num;
   num=*n;
   max_edge=num*(num-1);
   for(count=1;count<=max_edge;count++)
   {
       printf("Enter the origin and destination vertex %d: \n",count);
       scanf("%d %d", &origin,&destin);
       /*printf("Enter the destination vertex: \n");
       scanf("%d", &destin);*/
       if((origin==-1)||(destin==-1))
       {
           break;
       }
       if(origin>=num || destin>=num || origin<0 || destin<0)
       {
           printf("Invalid vertex\n");
           count--;
       }
       else adj[origin][destin]=1;
    }
}

void display_graph(int **adj,int *n)
{
    int i,j;
    for(i=0;i<*n;i++)
    {
        for(j=0;j<*n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}