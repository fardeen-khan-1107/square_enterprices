#include<stdio.h>
int search(int arr[5],int key)
{
    for(int i=0;i<5;i++)
        if(arr[i]==key)
            return 1;
        return -1;
}
void main()
{
    int arr[5],value;
    printf("enter the number to insert");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
     printf("enter the value to search");
     scanf("%d",&value);
     printf("%d", search(arr,value));
    
}

