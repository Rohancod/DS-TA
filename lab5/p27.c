#include<stdio.h>

int main(){

    int n ,N;

    printf("enter size of array ");
    scanf("%d",&n);

    printf("enter number to delete ");
    scanf("%d",&N);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element number %d ", i);
        scanf("%d", &arr[i]);
    }

    for(int i =0 ; i<n ;i++){
        if(arr[i]==N){
            int index = i;
            for(int i=index; i<n;i++){
              arr[i]=arr[i+1];
              }
              
        }

    }
    n--;
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}