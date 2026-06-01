//inserction sort

#include <stdio.h>
void insertionSort(int arr[],int n){
    int i=1;
    int j;
    int key;
    while(i<n){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        i++;
    }

}

void main(){
    int n;
    printf("Enter a size of an array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter a number : ");
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    printf("sorted array is : ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
