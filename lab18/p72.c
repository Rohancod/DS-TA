#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node *link;
};

struct node *P1 = NULL;
struct node *P2 = NULL;
struct node *P3 = NULL;

void insert(struct node **head, int c, int e)
{
    struct node *newnode =
        (struct node *)malloc(sizeof(struct node));

    newnode->coef = c;
    newnode->exp = e;
    newnode->link = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    struct node *temp = *head;

    while (temp->link != NULL)
        temp = temp->link;

    temp->link = newnode;
}

// Display polynomial
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coef, head->exp);

        if (head->link != NULL)
            printf(" + ");

        head = head->link;
    }

    printf("\n");
}

// Add two polynomials
void addPoly()
{
    struct node *p = P1;
    struct node *q = P2;

    while (p != NULL && q != NULL)
    {
        if (p->exp == q->exp)
        {
            insert(&P3,p->coef + q->coef,p->exp);

            p = p->link;
            q = q->link;
        }
        else if (p->exp > q->exp)
        {
            insert(&P3,p->coef,p->exp);

            p = p->link;
        }
        else
        {
            insert(&P3,
                   q->coef,
                   q->exp);

            q = q->link;
        }
    }

    while (p != NULL)
    {
        insert(&P3, p->coef, p->exp);
        p = p->link;
    }

    while (q != NULL)
    {
        insert(&P3, q->coef, q->exp);
        q = q->link;
    }
}

int main()
{
    // P1 = 5x² + 4x¹ + 2
    insert(&P1, 5, 2);
    insert(&P1, 4, 1);
    insert(&P1, 2, 0);

    // P2 = 3x² + 6x¹ + 7
    insert(&P2, 3, 2);
    insert(&P2, 6, 1);
    insert(&P2, 7, 0);

    printf("Polynomial 1:\n");
    display(P1);

    printf("Polynomial 2:\n");
    display(P2);

    addPoly();

    printf("Result:\n");
    display(P3);

    return 0;
}