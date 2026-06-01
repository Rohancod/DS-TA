#include<stdio.h>

int main(){

    int n,a,b,flag=0;
    printf("enter number ");
    scanf("%d",&a);
    printf("enter number ");
    scanf("%d",&b);
     
    while(a<b){
        flag=0;
        for(int i = 2 ; i<=a/2; i++){
        if(a%i==0){
         flag =1;
         break;
        }

    } 

    
        if(flag==0){
            printf("%d ",a);
        }

        a++;
    
   
}

 return 0;

}