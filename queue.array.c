#include<stdio.h>
#include<stdlib.h>
#define max  10
int front=0,rear=0;
int queue[max];
void enqueue();
void dequeue();
void display();
void main()
{
    int option;
    while(1)
    {
        printf("select your option");
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit");
        scanf("%d",&option);
        switch(option)
        {
            case 1:enqueue();
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default:
            printf("invalid option");
        }
    }
}
void enqueue()
{
    int item;
    if(rear==(max-1))
    {
        printf("queue is full");
    }   
    else
    {
        printf("enter the number to insert");
        scanf("%d",&item);
        queue[rear]=item;
        rear=rear+1;
    }
}
void dequeue()
{
    if(front==rear)
    {
        printf("queue is empty");
    }
    else
    {
        printf("the deleted element is %d",queue[front]);
        front=front+1;
    }
}
void display()
{
    if(front==rear)
    {
        printf("queue is empty");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d",queue[i]);
        }
    }
}