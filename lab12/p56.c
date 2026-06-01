#include<stdio.h>
#include<stdlib.h>
 int main(){

    
    int n,temp;

    printf("enter the size ");
    scanf("%d",&n);

    int *iptr = (int *)malloc(n*sizeof(int));
    
    for(int i =0;i<n;i++){
        printf("enter the number");
        scanf("%d",iptr+i);

    }
    
    for(int i =0;i<n;i++){
        for (int j = i+1; j < n; j++)
        {
            if(*(iptr+i)>(*(iptr+j))){

                temp=*(iptr+j);
                *(iptr+j)=*(iptr+i);
                *(iptr+i)=temp;
            
        }
        }
        
    }

     for(int i =0;i<n;i++){
       
        printf("%d ",*(iptr+i));
    }

    
    

   

    
    return 0;
 }