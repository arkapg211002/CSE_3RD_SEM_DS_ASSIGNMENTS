/*Create binary search tree and implement Preorder, Inorder 
and Postorder traversal non-recursively in C.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *newnode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void insert(struct node **root,int data)
{
    if(*root==NULL)
    {
        *root=newnode(data);
        return;
    }
    if(data<=(*root)->data)
        insert(&(*root)->left,data);
    else
        insert(&(*root)->right,data);
}

void display(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    display(root->left);
    display(root->right);
}

int main()
{
    int n,i,data;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element: ");
        scanf("%d",&data);
        insert(&root,data);
    }
    printf("\nThe binary search tree is: ");
    display(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    return 0;
}
