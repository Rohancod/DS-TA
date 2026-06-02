//binary search(iterative)

#include<stdio.h>


int main(){
    int arr[5]={1,3,7,10,55};

    int n;
    printf("Enter the number to be searched:");
    scanf("%d",&n); 

    int low=0,high=4,mid;

    while (low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==n){ 
            printf("Element found at index %d",mid);
            return 0;
        }else if(arr[mid]<n){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    
    return 0;
}





/*//binary search(recursive)

#include<stdio.h>
 

int binarySearch(int arr[], int low, int high, int n){
    if(low>high){
        return -1;
    }
    int mid=(low+high)/2;
    if(arr[mid]==n){
        return mid;
    }else if(arr[mid]<n){
        return binarySearch(arr, mid+1, high, n);
    }else{
        return binarySearch(arr, low, mid-1, n);
    }
}
int main(){ 
    int arr[5]={1,3,7,10,55};

    int n;
    printf("Enter the number ");
    scanf("%d",&n); 

    int result=binarySearch(arr, 0, 4, n);
    if(result==-1){
        printf(" not found");
    }else{
        printf("found at index %d",result);
    }
    
    return 0;
}*/