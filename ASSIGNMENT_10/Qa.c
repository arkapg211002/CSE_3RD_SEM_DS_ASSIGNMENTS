/*Write a program to sort an array using Insertion sort in 
C.
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,n,temp,a[10];
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(temp<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("The sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}