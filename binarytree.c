#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *head(int val)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

int  insert()
{
    int val;
    printf("enter the value");
    scanf("%d",&val);
    if(root==NULL)
    {
       root=head(val);
       return -1;
    }

   struct node *ptr=root;
   while(1)
   {
    if(val > ptr->data)
    {
        if(ptr->right==NULL)
        {
            ptr->right=head(val);
            return -1;
        }
        ptr = ptr->right;
    }
    else if(val < ptr->data)
    {
        if(ptr->left==NULL)
        {
            ptr->left=head(val);
            return -1;
        }
        ptr=ptr->left;
    }
  }
}
int inorder(struct node *root)
{
    //struct node *root;
    if(root==NULL)
        return -1;
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}

int main()
{

    insert();
    insert();
    insert();
    insert();
    inorder(root);
    
    return 0;
}