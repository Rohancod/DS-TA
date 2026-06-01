//WAP to find the smallest and largest elements in the Binary Search Tree.




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

int find_min(struct Node *root){

    if (root == NULL){
        return -1; 
    }

    struct Node *current = root;

    while (current->left != NULL){
        current = current->left;
    }
    return current->data;


}


int find_max(struct Node *root){        
    
    if (root == NULL){
        return -1; 
    }

    struct Node *current = root;

    while (current->right != NULL){
        current = current->right;
    }
    return current->data;
}


int main()
{
    struct Node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(20);

    int min = find_min(root);
    int max = find_max(root);

    printf("Minimum element in the BST: %d\n", min);
    printf("Maximum element in the BST: %d\n", max);

    return 0;
}