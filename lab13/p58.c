#include <stdio.h>
#include <stdlib.h>
int Insert_At_Fist();
int Insert_At_End();
int display();
int Delete_First_Node();
int Delete_Last_Node();

struct node
{
    int info;
    struct node *link;
};

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
            Insert_At_Fist();

            break;
        case 2:
            Insert_At_End();
            break;
        case 3:
            display();
            break;
        case 4:
            Delete_First_Node();
            break;

        case 5:
            Delete_Last_Node();
            break;

        default:
            break;
        }
    }

    return 0;
}

struct node *First = NULL;

int Insert_At_Fist()
{
    int n;
    printf("enter the element ");
    scanf("%d", &n);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("memory allocation failed");
        return 0;
    }
    newNode->info = n;
    newNode->link = First;
    First = newNode;
 
    return 0;
}

int Insert_At_End()
{
    int n;
    printf("enter the element ");
    scanf("%d", &n);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("memory allocation failed");
        return 0;
    }
    newNode->info = n;
    newNode->link = NULL;

    if (First == NULL)
    {
        First = newNode;
    }
    else
    {
        struct node *save = First;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    }

    return 0;
}
int Delete_First_Node()
{
    if (First == NULL)
    {
        printf("List is empty");
        return 0;
    }

    struct node *temp = First;
    First = First->link;
    free(temp);
    return 0;
}



int Delete_Last_Node()
{

    struct node *save = First;
    struct node *pred = save;

    while (save->link != NULL)
    {
        pred = save;
        save = save->link;
    }

    pred->link = NULL;
    free(save);
    return 0;
}
int display()
{

    struct node *save = First;
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    return 0;
}
struct node *last = NULL;
void deleteFromPosition(int position)
{
    int count = 1;
    struct node *save = First;
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