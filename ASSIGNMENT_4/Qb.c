#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};//defining linked list to implement queue
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int d)//function to insert a node in queue
{
	struct node* new_n;
	new_n = (struct node*)malloc(sizeof(struct node));
	new_n->data = d;
	new_n->next = NULL;
	if((front == NULL)&&(rear == NULL)){
		front = rear = new_n;
	}
	else{
		rear->next = new_n;
		rear = new_n;
	}
	
}
void print()//function to display the queue
{
	struct node* temp;
	if((front == NULL)&&(rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		temp = front;
		while(temp){
			printf("\n%d",temp->data);
			temp = temp->next;
		}
	}
}
void dequeue()//function to delete an element from a queue
{
	struct node *temp;
	temp = front;
	if((front == NULL)&&(rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		front = front->next;
		free(temp);
	}
}
int main()//main function to use all our declared function
{
	int opt,n,i,data;
	printf("Enter Your Choice:-");
	while(opt!=0){
		printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the size: ");
				scanf("%d",&n);
				printf("\nEnter your data\n");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
	}
}