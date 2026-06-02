//linear search

#include<stdio.h>

int main(){
    int arr[5]={1,3,2,10,55};

    int n;
    printf("Enter the number to be searched:");
    scanf("%d",&n); 

    for (int i = 0; i < 5; i++)
    {
       if(arr[i]==n){
        printf("Element found at index %d",i);
        return;
       }
    }
    
    return 0;
}