#include <stdio.h>

int main()
{
    int n, Li = 0, Si = 0,smallest=0,largest=0;
    printf("enter size of array ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element number %d ", i + 1);
        scanf("%d", &arr[i]);
    }
     smallest = arr[0], largest = arr[0];

    for(int i=0;i<n;i++){
        
        if (arr[i]<smallest){
            smallest = arr[i];
            Si=i;
        }

        if (arr[i]>largest){
            largest = arr[i];
            Li=i;
        }
    }
    

    printf("%d %d", Si+1, Li+1);
    
    return 0;
}