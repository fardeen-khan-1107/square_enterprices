#include<stdio.h>
#include<stdlib.h>
# define max 5
int front=-1,rear=-1;
int queue[max];
void enqueue();
void dequeue();
void display();
void main()
{
    int option;
    while(1)
    {
        printf("\nselect proper option");
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit");
        scanf("%d",&option);
        switch(option)
        {
            case 1:   enqueue();
                        break;
            case 2:
                    dequeue();
                    break;
            case 3:
                    display();
                    break;
            case 4: 
                    exit(0);
                    break;
            default:
                    printf("invalid option");
        }
    }
}
void enqueue()
{
    int item;
    if((rear+1)%max==front)
    {
        printf("queue is full");
    }
    else
    {  
        if(front==-1)
          front=0;
        printf("enter the value to insert");
        scanf("%d",&item);
        rear=(rear+1)%max;
        queue[rear]=item;
    }
}
void dequeue()
{
    if(front==-1||rear==-1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("the deleted value is %d",queue[front]);
        if(front==rear)
        {
          front=-1;
          rear=-1;
        }
        else
        {
        front=(front+1)%max;
        }
    }
}
void display()
{
    int i=front;
    if(front==rear)
    {
        printf("\nqueue is empty");
    }
    else{
    while(i!=rear)
    {
        printf("%d",queue[i]);
        i=(i+1)%max;
    }
    printf("%d",queue[rear]);
    }   
}