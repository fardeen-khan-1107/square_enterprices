#include<Stdio.h>
#include<stdlib.h>
int max=10;
int top=-1;
int stack[10];
void push();
void pop();
void display();
void main()
{
    int option;
    while(1)
    {
        printf("\nselect the following option");
        printf("\n1.push\n2.pop\n3.display\n4.exit");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                    push();
                    break;
            case 2:
                    pop();
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
void push(int val)
{
  if( top==max-1)
  {
    printf("stack is full");
  }
  else
  {
    printf("enter the element to insert");
    scanf("%d",&val);
    top=top+1;
    stack[top]=val;
  }
}
void pop()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("the deleted element is %d",stack[top]);
        top=top-1;
    }
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        for(int i=top;i>=0;--i)
        {
            printf("%d",stack[i]);
        }
    }
}





