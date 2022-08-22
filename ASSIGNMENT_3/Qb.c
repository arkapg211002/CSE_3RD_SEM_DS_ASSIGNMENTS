/*Write a menu driven C program to implement double ended queue.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX],front,rear;
void insert();
void del();
void display();
void main()
{
    int choice;
    front=-1;
    rear=-1;
    do
    {
        printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\t");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nInvalid choice");
        }
    }while(choice!=4);
}
void insert()
{
    int item;
    if(rear==MAX-1)
    {
        printf("\nQueue is full");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    if(rear==-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    printf("\nEnter the item: ");
    scanf("%d",&item);
    queue[rear]=item;
}
void del()
{
    if(front==-1)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\n%d is deleted",queue[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is empty");
        return;
    }
    for(i=front;i<=rear;i++)
    {
        printf("\n%d",queue[i]);
    }
}
