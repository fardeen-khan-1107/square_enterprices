#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
void insert()
{
    int item;
    struct node *ptr;  
    ptr=malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&item);
    ptr->data=item;
    if(head==NULL)
    {
        ptr->prev=NULL;
        ptr->next=NULL;
        head=ptr;
    }
    else
    {
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
}
void lastinsert()
{
    int item;
    struct node *temp,*ptr;
    ptr=malloc(sizeof(struct node));
    printf("enter the value");
    scanf("%d",&item);
    ptr->data=item;
    if(head==NULL)
    {
        ptr->prev=NULL;
        ptr->next=NULL;
        head=ptr;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;
        ptr->next=NULL;
    }
}
void randominsert()
{
    int item,loc;
    struct node *ptr=malloc(sizeof(struct node));
    printf("enter the element");
    scanf("%d",&item);
    printf("enter the location");
    scanf("%d",&loc);
    struct node* temp=head;
    for(int i=0;i<loc-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)
            printf("invalid position");
            free(ptr);
    }
    temp->data=item;
    ptr->next=temp->next;
    ptr->prev=temp;
    if(temp->next!=NULL)
    {
    temp->next->prev=ptr;
    }
    temp->next=ptr;
}
void delete()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
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
        head=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);

    }
}
void randomdelete()
{
    int loc;
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    printf("Enter the location to delete the value: ");
    scanf("%d", &loc);
    
    if (loc <= 0)
    {
        printf("Invalid location\n");
        return;
    }
    
    temp = head;
    for (int i = 1; i < loc && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL)
    {
        printf("Invalid location\n");
        return;
    }
    
    if (temp == head)
    {
        head = temp->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
    }
    
    free(temp);
}

int search()
{
    int key,loc;
    struct node *temp;
    printf("enter the value to search");
    scanf("%d",&key);
    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==key)
        {
            printf("key is found %d",loc);
        }
        temp=temp->next;
    }
    return -1;
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("the details are %d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
    insert();
    insert();
    lastinsert();
    insert();
    randominsert();
    display();
    lastdelete();
    randomdelete();
    delete();
    display();
        return 0;
}