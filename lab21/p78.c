#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int issymmetric(struct node *root1, struct node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    return (root1->data == root2->data) && 
    issymmetric(root1->left, root2->right) && 
    issymmetric(root1->right, root2->left);
}

int ismirror(struct node *root)
{
    return issymmetric(root->left, root->right);
}

