#include<stdio.h>
#include<stdlib.h>
 int main(){

    
    int n ;

    printf("enter the size of array");
    scanf("%d",&n);

    int *iptr = (int *)malloc(n*sizeof(int));
    
    for(int i =0;i<n;i++){
        printf("enter the number");
        scanf("%d",iptr+i);
    }

     for(int i =0;i<n;i++){
       
        printf("%d",*(iptr+i));
    }

    free(iptr);
    

    return 0;
 }