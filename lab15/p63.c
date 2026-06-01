//WAP to remove duplicate elements from a singly linked list.


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
 
void Insert_At_End()
{
    int n;
    printf("enter the element ");
    scanf("%d", &n);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = n;
    newNode->link = NULL;
    
    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    }
}

void display()
{
    struct node *save = first;
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->link;
    }
}
void unsortedremoveDuplicate()
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = first;

    while (ptr1 != NULL && ptr1->link != NULL)// not empty and not last node
    {
        ptr2 = ptr1;

        while (ptr2->link != NULL)
        {
            if (ptr1->info == ptr2->link->info)
            {
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
            }
            else
            {
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
    }
}
void sortedremoveDuplicate()
{
    struct node *current = first, *next_next;

    if (current == NULL)
        return;

    while (current->link != NULL)
    {
        if (current->info == current->link->info)
        {
            next_next = current->link->link;
            free(current->link);
            current->link = next_next;
        }
        else
        {
            current = current->link;
        }
    }
}
int main()
{
    int n;
    while (n != -1)
    {
        printf("enter choice");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            Insert_At_End();
            break;
        case 2:
            display();
            break;
        case 3:
            unsortedremoveDuplicate();
            break;
        case 4:
            sortedremoveDuplicate();
            break;
        
        default:
            printf("Invalid choice");
            exit(0);

        }

    }
    return 0;
}

