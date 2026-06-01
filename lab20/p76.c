#include <stdio.h>
#include <stdlib.h>

 struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;




struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// recursive insert function
struct node *insert(struct node *root,int value){

        if(root == NULL){
            root= createNode(value);
        }
 
        if(value < root->data){
            root->left = insert((root->left),value);
        }else if(value >root->data){
            root->right = insert((root->right),value);
        }
        
    return root;
}


struct node* deleteNode(struct node* root, int value) {
    if(root==NULL) {
        return NULL;
    }
    if((root)->data>value) {
        (root)->left = deleteNode((root)->left, value);
    }
    else if((root)->data<value) {
        (root)->right=deleteNode((root)->right, value);
    }
    else {
        
        if((root)->left==NULL) {
            struct node* save=(root)->right;
            free(root);
            return save;
        }  
        else if ((root)->right==NULL) {
            struct node* save=(root)->left;
            free(root);
            return save;
        }
        else {
            struct node* temp=(root)->right;
            while(temp->left!=NULL) {
                temp=temp->left;
            }
            (root)->data=temp->data;
            (root)->right=deleteNode((root)->right, temp->data);
        
        }
    }

    return root;
}



void searchNode(struct node* root, int value) {
    if ( root->data == value) {
        printf("Found %d", value);
    }
    if (value < root->data) {
        return searchNode((root->left), value);
    }
    else if (value > root->data) {
        return searchNode((root->right), value);
    }
    
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    printf("Enter numbers to insert in the tree \n");
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        root= insert(root,n);
    }

    printf("Inorder traversal of the tree:\n");
    inorder(root);
    printf("\n");   
    printf("Preorder traversal of the tree:\n");
    preorder(root);
    printf("\n");
    printf("Postorder traversal of the tree:\n");
    postorder(root);
    printf("\n");   
    searchNode(root, 5);
    
    return 0;
}
