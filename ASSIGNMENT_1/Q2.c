/* The classic way to evaluate a polynomial is Horner's Rule. */

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,i,*a,x,s;
    printf("Enter the polynomial order: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("\n");
    printf("Enter the coefficients of the polynomial: ");
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Enter coefficient %d: ",i+1);
        scanf("%d",&a[i]);
        printf("\n");
    }
    printf("Enter the value of x: ");
    scanf("%d",&x);
    printf("The value of the polynomial is: ");
    s=a[0];
    for(i=1;i<n;i++)
    {
        s=s*x+a[i];
    }
    printf("%d\n",s);

    

}