#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate mid point

        // If target is found
        if (arr[mid] == target) {
            return mid;
        }

        // If target is smaller, ignore the right half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is larger, ignore the left half
        else {
            left = mid + 1;
        }
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};  // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
