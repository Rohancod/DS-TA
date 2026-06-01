#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;

void insertFirst(int n)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = n;

    if (first == NULL)
    {
        newNode->link = newNode;
        first = last = newNode;
    }
    else
    {
        newNode->link = first;
        last->link = newNode;
        first = newNode;
    }
}

void insertEnd(int n)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = n;

    if (first == NULL)
    {
        newNode->link = newNode;
        first = last = newNode;
    }
    else
    {
        last->link = newNode;
        newNode->link = first;
        last = newNode;
    }
}

void deleteFromPosition(int position)
{
    int count = 1;
    struct node *save = first;
    struct node *pred = last;

    while (count < position && save != NULL)
    {
        pred = save;
        save = save->link;
        count++;
    }

    if (save == last)
    {
        last = pred;
    }

    pred->link = save->link;
    free(save);
}

void display()
{

    struct node *save = first;

    while (save != NULL)
    {
        printf("%d->", save->data);
        save = save->link;

        if (save == first) // break;
            break;
    }
    printf("(head)\n");
}

int main()
{
    int choice, data, position;

    while (1)
    {
        printf("Circular Linked List Menu");
        printf("1.Insert at Front\n");
        printf("2.Insert at End\n");
        printf("3.Delete at Position\n");
        printf("4.Display List\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at front: ");
            scanf("%d", &data);
            insertFirst(data);
            break;

        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertEnd(data);
            break;

        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteFromPosition(position);
            break;

        case 4:
            display();
            break;

        case 5:

            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}