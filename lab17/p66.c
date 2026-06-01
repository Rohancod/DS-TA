#include <stdio.h>
#include <stdlib.h>
int insertion();
int display();
int sort();

struct node
{
    int info;
    struct node *link;
};

struct node *First = NULL;
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
            insertion();
            break;
        case 2:
            sort();
            break;
        case 3:
            display();
            break;

        default:
            break;
        }
    }
    return 0;
}
int insertion()
{
    int n;
    printf("enter the element ");
    scanf("%d", &n);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
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

int sort()
{
    if (First == NULL)
        return 0;

    struct node *i, *j;
    int temp;

    for (i = First; i != NULL; i = i->link)
    {
        for (j = i->link; j != NULL; j = j->link)
        {
            if (i->info > j->info)
            {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    return 0;
}
int display()
{
    struct node *save = First;

    while (save != NULL)
    {
        printf("%d->", save->info);
        save = save->link;
    }
    return 0;
}