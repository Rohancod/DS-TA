#include <stdio.h>

int main (){

    int year=0;
    printf("enter year \n");
    scanf("%d",&year);

    if(year % 400 || (year %4==0 && year%100!=0)){
        printf("leap year");
    }else{
        printf("it is not a leap year");
    }
    
    return 0;
}