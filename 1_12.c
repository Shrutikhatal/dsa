#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Faculty struct representing a faculty member
struct Faculty {
    char name[50];
    char category[20];
    int rank;
};

// Merge function for merging two sorted sub-arrays
void merge(struct Faculty arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    struct Faculty L[n1], R[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (strcmp(L[i].category, R[j].category) < 0 ||
            (strcmp(L[i].category, R[j].category) == 0 && L[i].rank < R[j].rank)) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[] if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function for sorting the array
void merge_sort(struct Faculty arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves recursively
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Example usage
int main() {
    // Initialize the faculty data
    struct Faculty faculties[] = {
        {"John", "Associate Professor", 2},
        {"Tom", "Professor", 1},
        {"Mary", "Assistant Professor", 3},
        {"Sarah", "Professor", 2},
        {"Alex", "Assistant Professor", 1},
        {"David", "Associate Professor", 1},
        {"Emily", "Assistant Professor", 2},
        {"James", "Professor", 3},
        {"Rachel", "Associate Professor", 3}
    };

    // Get the number of faculties
    int n = sizeof(faculties) / sizeof(struct Faculty);

    // Sort the faculty data using Merge Sort
    merge_sort(faculties, 0, n - 1);

    // Print the sorted faculty data
    for (int i = 0; i < n; i++)
    {
         printf("%s %s %d\n",faculties[i].name,faculties[i].category,faculties[i].rank);
    }
    
   return 0;
}
