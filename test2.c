#include <stdio.h>
#include <stdlib.h>
#define V 5

struct node
{
    int data;
    struct node *next;
};

struct node *head[V];

void insert()
{
    struct node *ptr = malloc(sizeof(struct node));
    int src, dest;
    
    printf("Enter the source: ");
    scanf("%d", &src);
    
    printf("Enter the destination: ");
    scanf("%d", &dest);

    // Create and insert edge from src to dest
    ptr->data = dest;
    ptr->next = NULL;
    
    if (head[src] == NULL)
    {
        head[src] = ptr;
    }
    else
    {
        struct node *temp = head[src];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }

    // Create and insert edge from dest to src
    ptr = malloc(sizeof(struct node));
    ptr->data = src;
    ptr->next = NULL;

    if (head[dest] == NULL)
    {
        head[dest] = ptr;
    }
    else
    {
        struct node *temp = head[dest];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void delete()
{
    int src, dest;
    printf("Enter the source: ");
    scanf("%d", &src);
    
    printf("Enter the destination: ");
    scanf("%d", &dest);

    // Remove edge from src to dest
    struct node *ptr = head[src], *temp;
    if (head[src] == NULL)
    {
        printf("Underflow\n");
    }
    else if (head[src]->data == dest)
    {
        ptr = head[src];
        head[src] = head[src]->next;
        free(ptr);
    }
    else
    {
        ptr = head[src];
        while (ptr->next != NULL)
        {
            if (ptr->next->data == dest)
            {
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
            }
            ptr = ptr->next;
        }
    }

    // Remove edge from dest to src
    ptr = head[dest];
    if (head[dest] == NULL)
    {
        printf("Underflow\n");
    }
    else if (head[dest]->data == src)
    {
        ptr = head[dest];
        head[dest] = head[dest]->next;
        free(ptr);
    }
    else
    {
        ptr = head[dest];
        while (ptr->next != NULL)
        {
            if (ptr->next->data == src)
            {
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
            }
            ptr = ptr->next;
        }
    }
}

void display()
{
    for (int i = 0; i < V; i++)
    {
        struct node *temp = head[i];
        printf("adjList[%d] -> ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    for (int i = 0; i < V; i++)
    {
        head[i] = NULL;
    }

    insert(); // First edge
    insert(); // Second edge
    insert(); // Third edge
    insert(); // Fourth edge
    insert(); // Fifth edge
    insert();
    insert();
    
    
    printf("Adjacency List Representation of the Graph:\n");
    display();
    
    delete(); // Remove an edge
    delete(); // Remove another edge
    
    printf("Updated Adjacency List Representation of the Graph:\n");
    display();

    return 0;
}
