#include<stdio.h>
#include<stdlib.h>
#define v 5
struct node
{
    int data;
    struct node *next;
};
    struct node *head[v];

void insert()
{
    struct node *ptr=malloc(sizeof(struct node));
    int scr,dest;
    printf("enter the source");
    scanf("%d",&scr);
    printf("enter the destination");
    scanf("%d",&dest);
    ptr->data=dest;
    ptr->next=NULL;
    if(head[scr]==NULL)
    {
        head[scr]=ptr;
    }
    else
    {
        struct node *temp=head[scr];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }

    ptr=malloc(sizeof(struct node));
    ptr->data=scr;
    ptr->next=NULL;
    if(head[dest]==NULL)
    {
        head[dest]=ptr;
    }
    else
    {
        struct node *temp=head[dest];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
 
}
void delete()
{
    int src,dest;
    printf("enter the data to remove");
    scanf("%d",&src);
    scanf("%d",&dest);

    struct node *ptr=head[src],*temp;
    if(head[src]==NULL)
        printf("underflow");
    else if(head[src]->data==dest)
    {
        ptr=head[src];
        head[src]=head[src]->next;
        free(ptr);
    }
    else
    {
        ptr=head[src];
        while(ptr->next!=NULL)
        {
            if(ptr->next->data==dest)
            {
                temp=ptr->next;
                ptr->next=temp->next;
                free(temp);
            }
            ptr=ptr->next;
        }
    }

    ptr=head[dest];
    if(head[dest]==NULL)
        printf("underflow");
    else if(head[dest]->data==src)
    {
        ptr=head[dest];
        head[dest]=head[dest]->next;
        free(ptr);
    }
    else
    {
        ptr=head[dest];
        while(ptr->next!=NULL)
        {
            if(ptr->next->data==src)
            {
                temp=ptr->next;
                ptr->next=temp->next;
                free(temp);
            }
            ptr=ptr->next;
        }
    }
}

void display()
{
    for(int i=0;i<v;i++)
    {
    struct node *temp=head[i];
        while(temp!=NULL)
        {
            printf("%d",i);
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    for(int i=0;i<v;i++)
    {
          head[i]=NULL;
    }
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    delete();
    delete();
    display();
    return 0;
}