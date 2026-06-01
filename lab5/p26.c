#include<stdio.h>
int main (){
    int n,i,pos,val;
    printf("enter the size of array ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("enter a number ");
        scanf("%d",&arr[i]);
    }
    printf("enter the new value to insert ");
    scanf("%d",&val);

    for(i=0;i<=n;i++){
        if(val<arr[i]){
            pos=i;
            break;
        }
    }

    for(i=n;i>pos;i--){  
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    n++;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}