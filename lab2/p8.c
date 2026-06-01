#include<stdio.h>
int fact(int n);

int main(){
    int n;
    printf("enter number ");
    scanf("%d",&n);

    int ans = fact(n);
    printf("%d",ans);

     
    return 0;
}

int fact (int n){
     int ans =1;

     if(n==0||n==1){
        return 1;
     }else{
        return n*fact(n-1);
     }
}