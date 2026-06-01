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

int checkheight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftheight = checkheight(root->left);
    int rightheight = checkheight(root->right);
    if (leftheight == -1 || rightheight == -1)
    {
        return -1;
    }
    if (abs(leftheight - rightheight) > 1)
    {
        return -1;
    }

    return 1 + max(leftheight, rightheight);
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int isbalanced(struct node *root)
{
    if (checkheight(root) == -1)
    {
        return 0;
    }
    return 1;
}
