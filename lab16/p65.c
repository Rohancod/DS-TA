//. Write a program to reverse a linked list.


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;

void reverse()
{
    struct node *prev = NULL;
    struct node *current = FIRST;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->link; // Store the next node
        current->link = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to the current node
        current = next;       // Move to the next node
    }
    FIRST = prev; // Update FIRST to point to the new head of the reversed list
}

int main()
{
    int n = 0, n2 = 0;

    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));

    printf("enter the first element ");
    scanf("%d", &n);

    newnode->info = n;
    newnode->link = FIRST;
    FIRST = newnode;

    while (1)
    {
        printf("enter next element ");
        scanf("%d", &n2);

        if (n2 == -1)
        {
            break;
        }

        struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
        newnode->info = n2;
        newnode->link = NULL;
        struct node *save = FIRST;

        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }

    reverse();

    // Print the reversed linked list
    struct node *current = FIRST;
    printf("Reversed linked list: ");
    while (current != NULL)
    {
        printf("%d ", current->info);
        current = current->link;
    }
    printf("\n");

    return 0;
}