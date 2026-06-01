#include <stdio.h>

int main() {
    int n, m;

    printf("Enter size of first array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element number %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++) {
        printf("Enter element number %d: ", i);
        scanf("%d", &arr2[i]);
    }

    int size = n + m;
    int arr3[size];

    
    for (int i = 0; i < n; i++) {
        arr3[i] = arr[i];
    }

    
    for (int i = 0; i < m; i++) {
        arr3[n + i] = arr2[i];
    }

    printf("Merged array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}
