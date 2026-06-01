#include <stdio.h>

int main(){

    int days =0;
    int week=0;
    int month =0;
    int year =0;


    printf("enter days \n");
    scanf("%d",&days);

    year =days/365;
    days=days%365;
    week=days/7;
    days=days%7;

    printf("%d %d %d",year,week,days);





    return 0;
}