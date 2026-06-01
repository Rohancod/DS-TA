#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;

};

int main(){
    struct node* New= (struct node*)malloc(sizeof(struct node));

    New->info=8;
    New->link=NULL;

    printf("%d",New->info);

    free(New);

    return 0;
}
