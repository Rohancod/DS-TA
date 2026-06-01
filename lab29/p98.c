//You are given an array of positive integers and an integer K. Find the length of
//the longest subarray such that the sum of the subarray is less than or equal to K.

#include <stdio.h>
int Subarray(int arr[], int n, int K) {
    int maxLength = 0;
    int currentSum = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        currentSum += arr[end];

        while (currentSum > K) {
            currentSum -= arr[start];
            start++;
        }

        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    // for ( int i = start; i < start + maxLength; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    return maxLength;
}

int main() {
    //1, 2, 1, 0, 1, 1, 0
    int arr[] = {1, 2, 1, 0, 1, 1, 0};
    int K = 4;
    int n = 7;

    int result = Subarray(arr, n, K);
    printf("Length of the longest subarray with sum at most %d: %d\n", K, result);

    return 0;
}