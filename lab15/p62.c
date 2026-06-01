
//. Write a program to implement queue using singly linked list.
#include <stdio.h>
#include <stdlib.h>
int enqueue(int value);
int dequeue();
int peek();
int display();

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;

int main()
{
    int choice, value;

    while (1)
    {

        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
        break;
        }
    }

    return 0;
}

int enqueue(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = NULL;

    if (last == NULL)
    {
        first = last = newNode;
    }
    else
    {
        last->link = newNode;
        last = newNode;
    }

    return 0;
}

int dequeue()
{
    
    struct node *temp = first;
    
    first = first->link;

    free(temp);

    return 0;
}

int peek()
{
    
        printf("Front element:-> %d", first->info);
    

    return 0;
}

int display()
{

    struct node *save = first;

    while (save != NULL)
    {
        printf(" %d -> ", save->info);
        save = save->link;
    }
    return 0;
}