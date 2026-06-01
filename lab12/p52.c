#include<stdio.h>
#include<stdlib.h>
 int main(){

    
    int n ,total=0;

    printf("enter the size ");
    scanf("%d",&n);

    int *iptr = (int *)malloc(n*sizeof(int));
    
    for(int i =0;i<n;i++){
        printf("enter the number");
        scanf("%d",iptr+i);

        total+=*(iptr+i);


    }

    printf("%d",total);
free(iptr);
    
    return 0;
 }