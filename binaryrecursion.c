#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *head(int val)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct node *insert(struct node *root,int val)
{
    if(root==NULL)
        return head(val);
    if(val>root->data)
        root->right=insert(root->right,val);
    else if(val<root->data)
        root->left=insert(root->left,val);
    return root;
}
int getnumber(struct node *root)
{
    struct node *temp = root;
    while(temp->left !=NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
struct node *delete(struct node *root,int val)
{
    if(root==NULL)
        return root;
    if(root->data > val)
        root->left=delete(root->left,val);
    else if(root->data < val)
        root->right=delete(root->right,val);
    else
    {
        if(root->left==NULL && root->right==NULL)
        { 
            free(root);
            return NULL;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else
        {
            int val=getnumber(root->right);
            root->data=val;
            root->right=delete(root->right,val);
    }
    }
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}

int main()
{
    root=insert(root,50);
    root=insert(root,49);
    root=insert(root,90);
    root=insert(root,180);
    int data;
    scanf("%d",&data);
    root=delete(root,data);
    inorder(root);
    
    return 0;
}
