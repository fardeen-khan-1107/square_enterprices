#include<stdio.h>
#include<stdlib.h>
#define v 5
int arr[v][v];

int insert()
{
    int scr,dest;
    printf("enter the source");
    scanf("%d",&scr);
    printf("enter the destination");
    scanf("%d",&dest);
    arr[scr][dest]=1;
return 0;
}
void display()
{
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            printf("%d",arr[i][j]);
        printf("\n");
}
void search()
{
    int scr,dest;
    printf("enter the source");
    scanf("%d",&scr);
    printf("enter the destination");
    scanf("%d",&dest);
    if(arr[scr][dest]==1)
        printf("node is present");
    else
        printf("not found");
}
void delete()
{
    int scr,dest;
    printf("enter the source");
    scanf("%d",&scr);
    printf("enter the destination");
    scanf("%d",&dest);
    if(arr[scr][dest]==1)
        arr[scr][dest]=0;
    else
        printf("it is already null");
}
int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    delete();
    search();
    search();
    display();
return 0;
}