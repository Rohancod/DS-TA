#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *FIRST = NULL;

// Insert at end
void insert(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->info = data;
    newnode->link = NULL;

    if (FIRST == NULL)
    {
        FIRST = newnode;
        return;
    }

    struct node *temp = FIRST;

    while (temp->link != NULL)
        temp = temp->link;

    temp->link = newnode;
}

// Display list
void display()
{
    struct node *temp = FIRST;

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}

// Swap consecutive pairs
void swapPairs()
{
    if (FIRST == NULL || FIRST->link == NULL)
    {
        printf("Less than 2 nodes.\n");
        return;
    }

    struct node *pp = NULL;
    struct node *p = FIRST;
    struct node *c = FIRST->link;

    while (p != NULL && c != NULL)
    {
        struct node *next = c->link;

        // Swap links
        c->link = p;
        p->link = next;

        // Update head for first swap
        if (pp == NULL)
            FIRST = c;
        else
            pp->link = c;

        // Move pointers forward
        pp = p;
        p = next;

        if (p != NULL)
            c = p->link;
        else
            c = NULL;
    }
}


void freeList()
{
    struct node *temp;

    while (FIRST != NULL)
    {
        temp = FIRST;
        FIRST = FIRST->link;
        free(temp);
    }
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Swap Consecutive Nodes");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &data);
            insert(data);
            break;

        case 2:
            display();
            break;

        case 3:
            swapPairs();
            printf("Nodes Swapped Successfully.\n");
            break;

        case 4:
            freeList();
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}