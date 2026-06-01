// Quick Sort in C
#include <stdio.h>

void quick_sort(int arr[], int low, int high) {
    int i, j, pivot, temp;
    int flag;

    if (low < high) {
        i = low;
        j = high + 1;
        pivot = arr[low];
        flag = 1;

        while (flag == 1) {
            
            do {
                i++;
            } while (i <= high && arr[i] < pivot);


            do {
                j--;
            } while (arr[j] > pivot);

            if (i < j) {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } else {
                flag = 0;
            }
        }


        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;


        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
}

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
