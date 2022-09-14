/*Write a program to perform Linear Search on an array of integers.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,i,n,x;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            printf("The element is found at position %d",i+1);
            exit(0);
        }
    }
    printf("The element is not found");
    return 0;
}