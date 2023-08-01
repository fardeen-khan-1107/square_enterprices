#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void push()
{
    int val;
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter the element");
    scanf("%d",&val);
    ptr->data=val;
    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
    }
    else
    {
        
        ptr->next=head;
        head=ptr;
    }
}
void pop()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void main()
{
    push();
    push();
    push();
    push();
    display();
    pop();
    pop();
    display();
}