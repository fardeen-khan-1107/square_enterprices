#include<stdio.h>

void main()
{
    int n, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete the number: ");
    scanf("%d", &pos);

    for(int j = pos; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }

    n--;

    printf("Array after deletion:\n");
    for(int k = 0; k < n; k++)
    {
       printf("%d ", arr[k]);
    }
}
