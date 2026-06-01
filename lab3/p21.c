#include<stdio.h>

    int main   (){

        int n = 0, A=0,B=0;
    printf("enter size of array ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element number %d ", i + 1);
        scanf("%d", &arr[i]);
    }


    printf("enter number which is too be replaced");
    scanf("%d",&A);

    printf("enter number too be replaced by");
    scanf("%d",&B);

    for(int i=0;i<n;i++){
        if (arr[i]==A){
            arr[i]=B;
        }
    }

    for(int i=0; i<n;i++){
        printf("%d /n",arr[i]);
    }
        return 0;
    }
