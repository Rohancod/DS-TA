//WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n).

#include<stdio.h>
int main(){

    int n, ans=0;
    printf("enter number ");
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            ans+=j;
        }
    }

    printf("%d",ans);
    return 0;
}