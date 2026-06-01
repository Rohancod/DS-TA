//. Write a program to construct a binary tree from given Postorder and Preorder traversal sequence.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int post[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (post[i] == value)
            return i;
    }
    return -1;
}

struct Node *constructTree(int pre[], int post[], int prestart, int preend, int poststart, int postend)

{
    if (prestart > preend || poststart > postend){
        return NULL;
    }

    struct Node *root = newNode(pre[prestart]);

    if (prestart == preend){
        return root;
    }

    int index = search(post, poststart, postend, pre[prestart + 1]);

    int size = index - poststart + 1;

    root->left = constructTree(pre, post, prestart + 1, prestart + size, poststart, index);

    root->right = constructTree(pre, post, prestart + size + 1, preend, index + 1, postend - 1);
    return root;
    


}

void printInorder(struct Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main()
{
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);

    
    struct Node *root = constructTree(pre, post, 0, size - 1, 0 , size - 1);

    printf("Inorder traversal of constructed tree: ");
    printInorder(root);

    return 0;
}
