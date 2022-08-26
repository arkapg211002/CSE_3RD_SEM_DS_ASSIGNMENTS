/*Write a C program for Collision avoidance in Hash table
using Linear Probing.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int hash(int);
void insert(int);
void display();
int a[MAX], i;
void main()
{
    int ch, key;
    for (i = 0; i < MAX; i++)
        a[i] = -1;
    do
    {
printf("\n1.Insert\t2.Display\t3.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
        case 1:
            printf("Enter the key:");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
}
    } while (ch != 3);
}
int hash(int key)
{
    return (key % MAX);
}
void insert(int key)
{
    int index = hash(key);
    if (a[index] == -1)
        a[index] = key;
    else
    {
        while (a[index] != -1)
        {
            index = (index + 1) % MAX;
            if (index == hash(key))
            {
                printf("Hash table is full");
                return;
            }
        }
        a[index] = key;
    }
}
void display()
{
    for (i = 0; i < MAX; i++)
        printf("%d\t", a[i]);
}
