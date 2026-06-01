#include <stdio.h>

int main(){
    int n ;

    printf("enter size of array ");
    scanf("%d",&n);

    

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element number %d ", i);
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n;i++){
        for(int j =i+1 ; j<n;j++){
            if (arr[i]==arr[j]){
                for(int k=j;k<n;k++){
                    arr[k]=arr[k+1];
                }
                n--;
                j--;
            }
        }
    }

     for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}