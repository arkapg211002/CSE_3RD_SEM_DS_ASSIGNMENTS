#include<stdio.h>
#include<stdlib.h>
void display(int **,int,int);
int count(int **,int,int);
void sparse(int **,int,int);
void transpose(int **,int,int);
void main()
{
    int r,c,**p,i,j,cn;
    printf("\nEnter the number of rows: ");
    scanf("%d",&r);
    printf("\nEnter the number of columns: ");
    scanf("%d",&c);
    p=(int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)
    {
        p[i]=(int*)malloc(c*sizeof(int));
    }
    printf("\nEnter the elements: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("\nEnter the element in row %d and column %d: ",i+1,j+1);
            scanf("%d",&p[i][j]);
        }
    }
    display(p,r,c);
    cn=count(p,r,c);
    if(cn>((r*c)/2))
    {
        printf("\nThe matrix is sparse.\n");

        printf("\nThe matrix in 3 tuple form is: \n");
        printf("%d\t%d\t%d\n",c,r,cn);
        sparse(p,r,c);

        printf("\nThe transpose of the matrix is: \n");
        
        transpose(p,r,c);

    }
    else
    {
        printf("\nThe matrix is not sparse");
    }
}

void display(int **p,int r,int c)
{
    int i,j;
    printf("\nThe matrix is: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}

int count(int **p,int r,int c)
{
    int i,j,k,l,m,n,count=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(p[i][j]==0)
            {
                count++;
            }
        }
    }
    return count;
    
}

void sparse(int **p,int r,int c)
{
    int i,j,k,l,m,n;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(p[i][j]!=0)
            {
                printf("%d\t%d\t%d\n",i,j,p[i][j]);
            }
        }
    }
}

void transpose(int **p,int r,int c)
{
    int i,j,k,l,m,n;
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d\t",p[j][i]);
        }
        printf("\n");
    }
}