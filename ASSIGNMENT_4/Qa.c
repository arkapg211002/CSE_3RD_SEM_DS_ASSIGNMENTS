/*Implement Singly Linked List and related operations like insertion, deletion, display, reverse and sort in C.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
    char data;
    struct node *next;
};

struct node *head=NULL;
struct node *temp=NULL;
struct node *newnode=NULL;

void insert_at_beginning(char data)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

void insert_at_end(char data)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insert_at_position(char data,int position)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        int i=1;
        while(i<position-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void delete_at_beginning()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void delete_at_position(int position)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        int i=1;
        while(i<position-1)
        {
            temp=temp->next;
            i++;
        }
        temp->next=temp->next->next;
        free(temp->next);
    }
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%c ",temp->data);
            temp=temp->next;
        }
    }
}

void reverse()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            printf("%c ",temp->data);
            temp=temp->next;
        }
    }
}

void sort()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data>temp->next->data)
            {
                char tempdata=temp->data;
                temp->data=temp->next->data;
                temp->next->data=tempdata;
            }
            temp=temp->next;
        }
    }
}

int main()
{
    int choice;
    int data;
    int position;
    while(1)
    {
        printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert at position\t4.Delete at beginning\t5.Delete at end\t6.Delete at position\t7.Display\t8.Reverse\t9.Sort\t10.Exit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data: ");
                fflush(stdin);
                scanf("%d",&data);
                
                insert_at_beginning(data);
                break;
            case 2:
                printf("Enter the data: ");
                fflush(stdin);
                scanf("%d",&data);
                
                insert_at_end(data);
                break;
            case 3:
                printf("Enter the data: ");
                fflush(stdin);
                scanf("%d",&data);
                
                printf("Enter the position: ");
                fflush(stdin);
                scanf("%d",&position);

                insert_at_position(data,position);
                break;
            case 4:
                delete_at_beginning();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter the position: ");
                fflush(stdin);
                scanf("%d",&position);
                delete_at_position(position);
                break;
            case 7:
                display();
                break;
            case 8:
                reverse();
                break;
            case 9:
                sort();
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}




