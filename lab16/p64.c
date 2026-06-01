// Write a program to copy a linked list.

#include <stdio.h>
#include <stdlib.h>
int Insert_At_Fist();
int Insert_At_End();
int display();

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
            Insert_At_End();
            break;
        case 2:
            display();
            break;
        }

    }
    return 0;
}
    int Insert_At_End()
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
            printf("%d -> ", save->info);
            save = save->link;
        }
        return 0;
    }

    int copy()
    {
        struct node *save = First;
        struct node *pred = NULL;

        struct node *newnode= (struct node *)malloc(sizeof(struct node ));

        newnode->info=First->info;
        struct node *begin=newnode;  // head of new list
        while (save->link != NULL)
        {
           
            pred=newnode;
            save=save->link;
            newnode=(struct node *)malloc(sizeof(struct node ));
            pred->link=newnode;
            newnode->info=save->info;

        }

        newnode->link=NULL;


        
        return 0;
    }

