#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(int,struct node **);
void pop(struct node **);
void display(struct node **);
void peek(struct node **);
void isEmpty(struct node **);
void isFull(struct node **);

void push(int data,struct node **top)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nStack Overflow");
        return;
    }
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
}

void pop(struct node **top)
{
    if(*top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

void display(struct node **top)
{
    if(*top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = *top;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek(struct node **top)
{
    if(*top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", (*top)->data);
}

void isEmpty(struct node **top)
{
    if(*top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is not empty\n");
}

void isFull(struct node **top)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Stack is full\n");
        return;
    }
    else{
        free(newnode);
        printf("Stack is not full\n");
    }
    //free(newnode);
}

int main()
{
    struct node *top = NULL;
    int choice,data;
    while(1)
    {
        printf("\n1.Push\t2.Pop\t3.Display\t4.Peek\t5.IsEmpty\t6.IsFull\t7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                push(data,&top);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(&top);
                break;
            case 4:
                peek(&top);
                break;
            case 5:
                isEmpty(&top);
                break;
            case 6:
                isFull(&top);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
