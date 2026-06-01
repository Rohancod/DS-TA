#include <stdio.h>
#include <stdlib.h>
int insertion();
int display();
int gcd();
struct node * insert_gcd(int value, struct node *after);

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
            gcd();
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

int gcd()
{
    struct node *current = First;

    while (current != NULL && current->link != NULL)
    {
        int a = current->info;
        int b = current->link->info;
        int temp;

        while (b != 0)
        {
            temp = b;
            b = a % b;
            a = temp;
        }

        insert_gcd(a, current);
        current = current->link->link;
    }

    return 0;
}

struct node * insert_gcd(int value, struct node *after)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = after->link;
    after->link = newNode;
    return newNode;
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