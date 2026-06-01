#include <stdio.h>

int  main(){

    int sec=0;
    int hr=0;
    int min =0;

    printf("enter seconds \n");
    scanf("%d",&sec);

    hr= sec/3600;
    sec=sec%3600;
    min=sec/60;
    sec=sec%60;

    printf("%d %d %d" , hr,min,sec);


    return 0;
}