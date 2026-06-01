#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
void insertAtFirst(struct node **l, struct node **r, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    if (*l == NULL)
    {
        *l = *r = newNode;
       
    }
    else
    {
        newNode->rptr = *l;
        (*l)->lptr = newNode;
        *l = newNode;
    }
}
void insertAtLast(struct node **l, struct node **r, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    if (*l == NULL)
    {
        *l = newNode;
        *r = newNode;
    }
    else
    {

        newNode->lptr = *r;
        (*r)->rptr = newNode;

        *r = newNode;
    }
}
void display(struct node **l)
{
    struct node *save = *l;
    while (save != NULL)
    {
        printf("%d,", save->info);
        save = save->rptr;
    }
}
void delAtPos(struct node **l, struct node **r, int pos)
{
    struct node *save = *l;
    if (pos <= 0)
    {
        printf("invalid position");
    }
    if (pos == 1)
    {
        *l = save->rptr;
        save->rptr->lptr = NULL;
        free(save);
        return;
    }
    for (int i = 1; i < pos; i++)
    {
        save = save->rptr;
    }
    if (save == *r)
    {
        (*r)->lptr->rptr = NULL;
        *r = (*r)->lptr;
        free(save);
        return;
    }
    save->lptr->rptr = save->rptr;
    save->rptr->lptr = save->lptr;
}
int main()
{
    struct node *l1 = NULL;
    struct node *r1 = NULL;
    int x;
    while (1)
    {
        printf("Enter a value : ");
        scanf("%d", &x);
        if (x == -1)
        {
            break;
        }
        insertAtLast(&l1, &r1, x);
    }
    display(&l1);
    int pos;
    printf("Enter a position : ");
    scanf("%d", &pos);
    delAtPos(&l1, &r1, pos);
    display(&l1);

    return 0;
}
