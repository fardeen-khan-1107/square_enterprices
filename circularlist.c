#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[10];
    int roll;
    float mark1;
    float mark2;
    float mark3;
    float total;
    struct node *next;
};
struct node *head;
void insert()
{
    struct node *ptr,*temp;
    ptr=malloc(sizeof(struct node));
    printf("\nenter the data of the student");
    scanf("%s%d%f%f%f",ptr->name,&ptr->roll,&ptr->mark1,&ptr->mark2,&ptr->mark3);
    printf("the total marks of the student is");
    ptr->total=ptr->mark1+ptr->mark2+ptr->mark3;
    printf("the result is %.2f",ptr->total);
    if(head==NULL)
    {
        head=ptr;
        ptr->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        temp->next=ptr;
        head=ptr;
    }
}
void lastinsert()
{
    struct node *ptr,*temp;
    ptr=malloc(sizeof(struct node));
    printf("enter the details of the student");
    scanf("%s%d%f%f%f",ptr->name,&ptr->roll,&ptr->mark1,&ptr->mark2,&ptr->mark3);
    printf("the total marks of the student is");
    ptr->total=ptr->mark1+ptr->mark2+ptr->mark3;
    printf("the result is %.2f",ptr->total);
    if(head==NULL)
    {
        head=ptr;
        ptr->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        temp->next=ptr;
    }
}
void delete()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        free(head);
        head=temp->next;
        
    }
}
void lastdelete()
{
    struct node *temp,*temp1;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head==NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        free(temp);
    }
}
void display()
{
    struct node *ptr;
    ptr=head;
    do
    {
        printf("\n%s\n%d\n%.2f\n%.2f\n%.2f\n%d\n",ptr->name,ptr->roll,ptr->mark1,ptr->mark2,ptr->mark3,ptr->total);
        ptr=ptr->next;
    }
    while(ptr!=head);

}        
        
int main()
{
    insert();
    insert();
    lastinsert();
    display();
    delete();
    lastdelete();
    display();

        return 0;
}