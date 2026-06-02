//bubble sort

#include <stdio.h>

void bubblesort(int arr[],int n){

    int exchanged=0;
    for(int i =0 ; i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                exchanged++;
                
                }
            if(exchanged==0){
            printf("Already sorted \n");
            return;
        }

        }
        
    }

    
}

int main(){
    int arr[5]={9,6,8,99,88};

    bubblesort(arr,5);

    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
