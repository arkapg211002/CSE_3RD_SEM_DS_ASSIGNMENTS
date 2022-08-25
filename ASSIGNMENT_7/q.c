#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char data;
	struct node* left;
	struct node* right;
	struct node* next;
};

struct node *head=NULL;
struct node *tail=NULL;
struct node* newNode(char data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	
	return (node);
}
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c ", node->data);
}
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    printf("%c ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}
void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	else
    {
	
	    printInorder(node->left);

	
	    printf("%c ", node->data);

	
	    printInorder(node->right);
	}
}

void push(struct node* x)
{
	if(head==NULL)
	head = x;
	else
	{
		(x)->next = head;
		head = x;
	}
	
}
struct node* pop()
{
	
	struct node* p = head;
	head = head->next;
	return p;
}
int main()
{
	//char s[] = {'A','B','C','*','+','D','/'};
    char *s;
    int i,l;
    s = (char*)malloc(sizeof(char)*100);
    printf("\nEnter the expression: ");
    fflush(stdin);
    scanf("%s", s);
   
    l=strlen(s);
	//int l = sizeof(s) / sizeof(s[0]) ;
	struct node *x, *y, *z;
	for (i = 0; i < l; i++) {
		
		if (s[i] == '+' || s[i] == '-' || s[i] == '*'
			|| s[i] == '/' || s[i] == '^') {
			z = newNode(s[i]);
			x = pop();
			y = pop();
			z->left = y;
			z->right = x;
			push(z);
		}
		else {
			z = newNode(s[i]);
			push(z);
		}
	}
	printf(" The Inorder Traversal of Expression Tree: ");
	printInorder(z);
    printf("\n");
    printf(" The Preorder Traversal of Expression Tree: ");
    printPreorder(z);
    printf("\n");
    printf(" The Postorder Traversal of Expression Tree: ");
    printPostorder(z);
    printf("\n");
	return 0;
}
