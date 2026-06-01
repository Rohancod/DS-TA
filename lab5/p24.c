#include<stdio.h>

int main(){

    int n ,index, N;

    printf("enter size of array ");
    scanf("%d",&n);
     int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element number %d ", i);
        scanf("%d", &arr[i]);
    }
    printf("enter the index ");
    scanf("%d",&index);

    printf("enter new number");
    scanf("%d",&N);


    for(int i =n;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=N;
    n++;

    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}


