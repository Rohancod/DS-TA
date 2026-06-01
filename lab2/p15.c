 //WAP to print Armstrong number from 1 to 1000.

#include<stdio.h>
int main(){

    int n, sum=0, temp, rem;
    printf("Armstrong numbers from 1 to 1000 are: \n");
    for(n=1; n<=1000; n++){
        temp = n;
        sum = 0;
        while(temp != 0){
            rem = temp % 10;
            sum += rem * rem * rem;
            temp /= 10;
        }
        if(sum == n){
            printf("%d ", n);
        }
    }
    return 0;
}