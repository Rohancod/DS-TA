//WAP to delete alternate nodes of a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next  = NULL;
    return newNode;
}

void deleteAlternateNodes(struct node* root) {
    if (root == NULL) {
        return;
    }
    
    struct node* temp = root->next;
    
    if (temp != NULL) {
        root->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = root;
        }
        free(temp);
    }
    
    deleteAlternateNodes(root->next);
}



