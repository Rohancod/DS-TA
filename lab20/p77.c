#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node *CreateNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int areSame(struct node *P , struct node *Q){
    if(P == NULL && Q == NULL){
        return 1;
    }
    if(P == NULL || Q == NULL){
        return 0;
    }
    
    return (P->data == Q->data) && areSame(P->left, Q->left) && areSame(P->right, Q->right);
}

int main(){
    struct node *root1 = CreateNode(1);
    root1->left = CreateNode(2);
    root1->right = CreateNode(3);

    struct node *root2 = CreateNode(1);
    root2->left = CreateNode(2);
    root2->right = CreateNode(4);

    if(areSame(root1, root2)){
        printf("The trees are the same.\n");
    } else {
        printf("The trees are not the same.\n");
    }

    return 0;
}