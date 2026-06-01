#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *FIRST = NULL;
struct node *FIRST2 = NULL;

// Insert at end in Circular Linked List
void insert(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;

    if (FIRST == NULL)
    {
        FIRST = newnode;
        newnode->link = FIRST;
        return;
    }

    struct node *temp = FIRST;

    while (temp->link != FIRST)
        temp = temp->link;

    temp->link = newnode;
    newnode->link = FIRST;
}

// Display Circular Linked List
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    struct node *temp = head;

    do
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    } while (temp != head);

    printf("(BACK TO HEAD)\n");
}

// Split list into two halves
void splitList()
{
    if (FIRST == NULL || FIRST->link == FIRST)
    {
        printf("Cannot Split\n");
        return;
    }

    int count = 1;

    struct node *temp = FIRST->link;

    while (temp != FIRST)
    {
        count++;
        temp = temp->link;
    }

    struct node *save = FIRST;
    struct node *pred = save;

    int i = 0;

    while (i != (count / 2))
    {
        pred = save;
        save = save->link;
        i++;
    }

    // End first list
    pred->link = FIRST;

    // Start second list
    FIRST2 = save;

    // Find last node of second half
    while (save->link != FIRST)
    {
        save = save->link;
    }

    save->link = FIRST2;

    printf("List Split Successfully\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1.Insert");
        printf("\n2.Display First List");
        printf("\n3.Split");
        printf("\n4.Display Second List");
        printf("\n5.Exit");
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
            printf("\nFIRST LIST:\n");
            display(FIRST);
            break;

        case 3:
            splitList();
            break;

        case 4:
            printf("\nSECOND LIST:\n");
            display(FIRST2);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}