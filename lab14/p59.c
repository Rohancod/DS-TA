#include <stdio.h>
#include <stdlib.h>


struct node
{
    int info;
    struct node *link;
};

struct node *intsert(struct node *first, int info)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->info = info;
    newnode->link = NULL;

    if (first == NULL)
    {
        return newnode;
    }

    struct node *save = first;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newnode;

    return first;
}

int aresame(struct node *first1, struct node *first2)
{

    while (first1 != NULL && first2 != NULL)
    {
        if (first1->info != first2->info)
        {
            return 0;
        }

        first1 = first1->link;
        first2 = first2->link;
    }
    return 1;
}

struct node *createList()
{
    struct node *first = NULL;
    int n;
    printf("Enter elements (-1 to end): ");
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
        {
            break;
        }
        first = intsert(first, n);
    }
    return first;
}

int main()
{
    struct node *first1 = createList();
    struct node *first2 = createList();


    if (aresame(first1, first2))
        printf("The two linked lists are the same");
    else
        printf("The two linked lists are different");

    return 0;
}
