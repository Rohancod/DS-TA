#include <stdio.h>

int main(){
    int n;
    printf("enter size of array ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<n;i++){
        printf("enter element number %d ",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i=0; i<n;i++){
        printf("%d",arr[i]);
    }

    return 0;
}