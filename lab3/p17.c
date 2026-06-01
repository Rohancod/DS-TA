#include<stdio.h>

int main(){

    int n , m;

    printf("enter number 1 ");
    scanf("%d",&n);

    printf("enter number 2");
    scanf("%d",&m);

     int total = 0;
    while (n<=m)
    {
      total= total+n;
      n++;
    }
    printf("%d",total);
    return 0;
}