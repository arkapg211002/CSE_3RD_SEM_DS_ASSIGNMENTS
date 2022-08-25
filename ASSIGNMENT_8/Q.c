/*Create Priority Queue and implement enqueue and 
dequeue operations in C*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};



void enqueue(int data,struct node **front,struct node **rear)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(*front==NULL)
    {
        *front=temp;
        *rear=temp;
    }
    else
    {
        (*rear)->next=temp;
        *rear=temp;
    }
}


void dequeue(struct node **front,struct node **rear)
{
    if(*front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp=*front;
        printf("%d\n",temp->data);
        *front=temp->next;
        if(*front==NULL)
        {
            *rear=NULL;
        }
        free(temp);
        
    }
}


void display(struct node **front)
{
    if(*front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp=*front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    int choice,data;
    struct node *front = NULL;
    struct node *rear = NULL;
    while(1)
    {
        printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter data to be enqueued\n");
                    scanf("%d",&data);
                    enqueue(data,&front,&rear);
                    break;
            case 2: 
                    printf("\nThe dequeued element is\n");
                    dequeue(&front,&rear);
                    break;
            case 3: display(&front);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
