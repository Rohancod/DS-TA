// merge sort

#include <stdio.h>

void merge(int arr[], int low, int high, int mid)
{
    int i = low, j = mid + 1, k = low;

    int tempB[high - low + 1];

    while (i <= mid && j <= high)

    {
        if (arr[i] < arr[j])
        {
            tempB[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            tempB[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        tempB[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        tempB[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = tempB[i];
    }
}


void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = 7;

    mergesort(arr, 0, size - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
