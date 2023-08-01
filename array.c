#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,pos,num;
    printf("entered the five elements");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the postion");
    scanf("%d",&pos);
    printf("enter the element");
    scanf("%d",&num);
    for(int j=n;j>pos;j--)
    {
        arr[j]=arr[j-1];
    }
    arr[pos]=num;
    for(int i=0;i<=n;i++)
    {
        printf("%d\n",arr[i]);
    }
}