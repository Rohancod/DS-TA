#include <stdio.h>

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int n = 6;

    int low = 0;
    int mid = 0;
    int high = n - 1;

//dnf
    while (mid <= high) {
        if (nums[mid] == 0) {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        } 
        else {
            int temp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = temp;
            high--;
        }
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
