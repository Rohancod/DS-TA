#include <stdio.h>
#include <stdlib.h>
int display();

struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;

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

    
//=======================================
    
 
    struct node *current = FIRST;
    while (current != NULL)
    {
        struct node *prev = current;
        struct node *check = current->link;

        while (check != NULL)
        {
            if (check->info == current->info)
            {
                
                prev->link = check->link;
                free(check);
                check = prev->link; //update to next node
            }
            else
            {
                prev = check;
                check = check->link;
            }
        }

        current = current->link;
    }
    display();

    return 0;
}

    

int display()
{

    struct node *save = FIRST;

    while (save != NULL)
    {
        printf(" %d -> ", save->info);
        save = save->link;
    }
    return 0;
}
