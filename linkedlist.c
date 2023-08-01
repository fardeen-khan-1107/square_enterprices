#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void beginsert();
void lastinsert();
void randominsert();
void delete();
void lastdelete();
void randomdelete();
void display();
void main()
{
    int option;
    for(;;)
    {
        printf("enter your option");
        printf("\n1.insert\n2.lastinsert\n3.randominsert\n4.delete\n5.lastdelete\n6.randomdelete\n7.display\n8.exit");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                    beginsert();
                    break;
            case 2:
                    lastinsert();
                    break;
            case 3:
                    randominsert();
                    break;
            case 4:
                    delete();
                    break;
            case 5:
                    lastdelete();
                    break;
            case 6:
                    randomdelete();
                    break;
            case 7:
                    display();
                    break;
            case 8:
                    exit(0);
                    break;
            default:
                    printf("invalid option");        
        }
    }
}
void beginsert()
{
    int val;
    struct node *temp, *ptr=(struct node*)malloc(sizeof (struct node));
    printf("enter the value to insert");
    scanf("%d",&val);
    ptr->data=val;
    if(ptr==NULL)
    {
      printf("overflow");
    }
    else
    {
        ptr->next=head;
        head=ptr;
    }
}
void lastinsert()
{
    int val;
    struct node *temp, *ptr=(struct node *)malloc(sizeof(struct node));
    printf("enter the element to insert");
    scanf("%d",&val);
    ptr->data=val;
    if(ptr==NULL)
    {
        printf("overflow");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
    }

}
void randominsert()
{
    int loc,val,i;
    struct node *temp,*ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("overflow");
    }
    else
    {
    printf("enter the element to insert");
    scanf("%d",&val);
    ptr->data=val;
    printf("enter the location to insert the data");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<loc;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("can't insert node");
        }
    }
    ptr->next=temp->next;
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
    else
    {
        temp=head;
        head=head->next;
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
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
    }
}
void randomdelete()
{
    int loc;
     struct node *temp,*temp1;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
         printf("enter the locaion to delete the value");
        scanf("%d",&loc);
        temp=head;
        for(int i=0;i<loc;i++)
        {
               temp1=temp;
               temp=temp->next;
               if(temp==NULL)
               {
                printf("can't delete");
               }    
        }
          temp1->next=temp->next;
          free(temp);
    }
}
void display()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("the value is %d\n",ptr->data);
        ptr=ptr->next;
    }
}

