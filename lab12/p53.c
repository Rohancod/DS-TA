#include<stdio.h>
#include<stdlib.h>
 int main(){

    
    int n ;

    printf("enter the size ");
    scanf("%d",&n);

    int *iptr = (int *)malloc(n*sizeof(int));
    
    for(int i =0;i<n;i++){
        printf("enter the number");
        scanf("%d",iptr+i);

    }
    int largest = *(iptr);
    for(int i =0;i<n;i++){
        if(*(iptr+i)>largest){
            largest=*(iptr+i);
        }
    }

    printf("%d is largest. ",largest);
    free(iptr);
    

   

    
    return 0;
 }