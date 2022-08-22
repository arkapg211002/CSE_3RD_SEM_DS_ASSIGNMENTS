/*Implement Doubly Linked List and perform insertion, deletion, display and reverse in C.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;
struct node *tail=NULL;

void insert_beg(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insert_end(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}

void insert_pos(int data,int pos)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        struct node *ptr=head;
        int i=1;
        while(ptr!=NULL && i<pos)
        {
            ptr=ptr->next;
            i++;
        }
        if(ptr==NULL)
        {
            printf("\nPosition not found");
        }
        else
        {
            temp->next=ptr;
            temp->prev=ptr->prev;
            ptr->prev->next=temp;
            ptr->prev=temp;
        }
    }
}

void delete_beg()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void delete_end()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
    }
}

void delete_pos(int pos)
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *ptr=head;
        int i=1;
        while(ptr!=NULL && i<pos)
        {
            ptr=ptr->next;
            i++;
        }
        if(ptr==NULL)
        {
            printf("\nPosition not found");
        }
        else
        {
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr);
        }
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *ptr=head;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void reverse()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *ptr=tail;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->prev;
        }
    }
}

int main()
{
    int choice,data,pos;
    while(1)
    {
        printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert at position\t4.Delete from beginning\t5.Delete from end\t6.Delete from position\t7.Display\t8.Reverse\t9.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data: ");
                scanf("%d",&data);
                insert_beg(data);
                break;
            case 2:
                printf("\nEnter the data: ");
                scanf("%d",&data);
                insert_end(data);
                break;
            case 3:
                printf("\nEnter the data: ");
                scanf("%d",&data);
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                insert_pos(data,pos);
                break;
            case 4:
                delete_beg();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                delete_pos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                reverse();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}

