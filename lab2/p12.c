#include<stdio.h>

int main(){

    int n,count=0;
    printf("enter number ");
    scanf("%d",&n);
     
    for(int i =2 ; i<=n; i++){
        if(n%i==0){
         count++;
        }
    } 

    if(count==1){
        printf("the number is prime");
    }else{
        printf("the number is not prime");
    }
    return 0;
}