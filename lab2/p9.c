#include<stdio.h>

int main(){
    int ans=1,n,b;

    printf("enter base ");
    scanf("%d",&n);
    printf("enter exp");
    scanf("%d",&b);

    for(int i=0;i<b;i++){
        ans*=n;
    }
    
    printf("%d",ans);
    return 0;
}