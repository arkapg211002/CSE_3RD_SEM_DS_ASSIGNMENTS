#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define waiting 2
#define visited 3
void insert_queue(int *queue,int *front,int *rear,int v,int *n);
int delete_queue(int *queue,int *front,int *rear,int *n);
int isEmpty_queue(int *front,int *rear);
void create_graph(int **adj,int *n);
void BF_Traversal(int **adj,int *state,int *queue,int *front,int *rear,int *n);
void BFS(int **adj,int *state,int *queue,int *front,int *rear,int *n,int v);
void display_graph(int **adj,int *n);
void main()
{
    int n,**adj,i,j,v,*state,*queue,front=-1,rear=-1;
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    adj=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        adj[i]=(int*)malloc(n*sizeof(int));
    }
    state=(int*)malloc(n*sizeof(int));
    queue=(int*)malloc(n*sizeof(int));
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
    printf("\nThe BFS Traversal is: \n");
    BF_Traversal(adj,state,queue,&front,&rear,&n);



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
void BF_Traversal(int **adj,int *state,int *queue,int *front,int *rear,int *n)
{
    int i,j,v;
    for(i=0;i<*n;i++)
    {
        state[i]=initial;
    }
    printf("Enter Start Vertex for BFS: \n");
    scanf("%d", &v);
    BFS(adj,state,queue,front,rear,n,v);
}

void BFS(int **adj,int *state,int *queue,int *front,int *rear,int *n,int v)
{
    int i;
    insert_queue(queue,front,rear,v,n);
    state[v]=waiting;
    while(!isEmpty_queue(front,rear))
    {
        v=delete_queue(queue,front,rear,n);
        printf("%d ",v);
        state[v]=visited;
        for(i=0;i<*n;i++)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
                insert_queue(queue,front,rear,i,n);
                state[i]=waiting;
            }
        }
    }
    printf("\n");
}

void insert_queue(int *queue,int *front,int *rear,int v,int *n)
{
    if(*rear==*n-1)
    {
        printf("Queue overflow\n");
        
    }
    else
    {
        if(*front==-1)
        {
            *front=0;
        }
        *rear=(*rear+1);
        queue[*rear]=v;
    }
}

int isEmpty_queue(int *front,int *rear)
{
    if(*front==-1 || *front>*rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int delete_queue(int *queue,int *front,int *rear,int *n)
{
    int v;
    if(*front==-1 || *front>*rear)
    {
        printf("Queue is underflow\n");
        exit(1);
    }
    v=queue[*front];
    *front=(*front+1);
    return v;
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