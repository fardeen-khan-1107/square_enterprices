#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
void enqueue()
{
    int data;
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter the value yo insert");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=rear=ptr;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
    }
}
int dequeue()
{
     struct node *temp;
     if(front==NULL)
     {
        return 0;
     }
     else
     {
        temp=front;
        int item=front->data;
        front=front->next;
        if(front== NULL)
        {
            rear=NULL;
        }
        free(temp);
        return item;
     }
}
void display()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        temp=front;
        printf("\nthe remaining elements are\n");
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;

        }
        printf("\n");
    }
}
int main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    printf("%d",dequeue());
    printf("%d",dequeue());
    display();
    return 0;
}