/*Write a program to perform binary search on an array of integers.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,i,n,x,first,last,mid;
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
    first=0;
    last=n-1;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(a[mid]==x)
        {
            printf("The element is found at position %d",mid+1);
            exit(0);
        }
        else if(a[mid]<x)
        {
            first=mid+1;
        }
        else
        {
            last=mid-1;
        }
    }
    printf("The element is not found");
    return 0;
}