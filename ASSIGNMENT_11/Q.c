/*Implement Linear, Binary and Interpolation search in C.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void linear(int *, int, int);
void binary(int *, int, int);
int interpolation(int *, int, int);
void main()
{
    int ch, *arr, n, i, key, pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("The array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // sorting
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\nEnter the key to be searched: ");
    scanf("%d", &key);
    printf("\nLinear Search");
    linear(arr, n, key);
    printf("\nBinary Search");
    binary(arr, n, key);
    printf("\nInterpolation Search");
    interpolation(arr, n, key);

}

void linear(int *arr, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("\nKey found at position %d\n", i + 1);
            break;
        }
    }
    if (i == n)
    {
        printf("\nKey not found\n");
    }
}

void binary(int *arr, int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            printf("\nKey found at position %d\n", mid + 1);
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (low > high)
    {
        printf("\nKey not found\n");
    }
}

int interpolation(int *arr, int n, int key)
{
    int lo = 0;
    int hi = n - 1;
    int mid = -1;
    int comparisons = 1;
    int index = -1;

    while (lo <= hi)
    {
        printf("\nComparison %d  \n", comparisons);
        printf("lo : %d, arr[%d] = %d\n", lo, lo, arr[lo]);
        printf("hi : %d, arr[%d] = %d\n", hi, hi, arr[hi]);
        comparisons++;
        mid = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (key - arr[lo]));
        printf("mid = %d\n", mid);
        if (arr[mid] == key)
        {
            index = mid;
            break;
        }
        else
        {
            if (arr[mid] < key)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
    printf("\nTotal comparisons made: %d", --comparisons);
    return index;
}