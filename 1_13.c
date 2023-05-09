#include <stdio.h>

void identifySwappedPair(int arr[], int n) {
    int first = -1, second = -1;

    // Traverse the array from left to right
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            first = i;
            break;
        }
    }

    // Traverse the array from right to left
    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            second = i;
            break;
        }
    }

    // Swap the elements at indices first and second
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;

    // Print the indices of the swapped elements
    printf("Swapped elements: %d, %d\n", arr[first], arr[second]);
    printf("Swapped positions: %d, %d\n", first, second);
}

int main() {
    int arr[] = {1, 3, 5, 4, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    identifySwappedPair(arr, n);

    return 0;
}
