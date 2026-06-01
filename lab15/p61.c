// Write a program to implement stack using singly linked list.
// insert first delete first
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *top = NULL;
    int choice, value;

    while (1)
    {
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            top = push(top, value);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            display(top);
            break;
        case 5:

            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

struct node *push(struct node *top, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = top;
    top = newNode;
    return top;
}
struct node *pop(struct node *top)
{
    struct node *temp = top;
    printf("Popped: %d", temp->data);
    top = top->link;
    free(temp);
    return top;
}

int peek(struct node *top)
{

    printf("Top element: %d", top->data);

    return 0;
}

int display(struct node *top)
{

    struct node *save = top;

    while (save != NULL)
    {
        printf(" %d -> ", save->data);
        save = save->link;
    }
    return 0;
}
