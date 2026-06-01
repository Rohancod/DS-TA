#include<stdio.h>

int main (){
    int n, index;
    printf("enter size of array ");
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element number %d ", i);
        scanf("%d", &arr[i]);
    }

    printf("enter index");
    scanf("%d",&index);

    for(int i=index; i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;

    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }

    return 0;
}