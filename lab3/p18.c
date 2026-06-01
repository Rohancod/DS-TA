#include<stdio.h>

int main(){
    int n,index;
    printf("enter size of array");
    scanf("%d",&n);

   

    int arr[n],total=0,count=0;

    for(int i=0; i<n;i++){
        printf("enter element number %d ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("enter index of array");
    scanf("%d",&index);

    for(int i=0;i<index;i++){

        total= total+ arr[i];
        count++;

    }
    float avg =0;
    printf("%d %d ", total, count);
     avg = (float)total/count;

    printf(" avg = %f",avg);



    return 0;
}