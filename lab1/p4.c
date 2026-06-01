#include <stdio.h>
 int main(){
    int a=0, b=0, c=0;
    printf("enter number 1");
    scanf("%d",&a);
    printf("enter number 2");
    scanf("%d",&b);
    printf("enter number 3");
    scanf("%d",&c);

    if(a>b){
        if(a>c){
            printf("largest number is %d ", a );
        }else{
            printf("largest number is %d",c);
        }
    }else{
        if(b>c){
            printf("largest number is %d",b);

        }else{
            printf("largest number is %d",c);
        }
    }
    return 0;
 }