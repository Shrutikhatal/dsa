#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Faculty {
    char faculty_name[50];
    int faculty_ID;
    char subject_codes[10];
    char class_names[10];
};

void swap(struct Faculty* a, struct Faculty* b) {
    struct Faculty temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Faculty arr[], int n, int i, int* swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].faculty_ID > arr[largest].faculty_ID)
        largest = left;

    if (right < n && arr[right].faculty_ID > arr[largest].faculty_ID)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*swapCount)++;
        heapify(arr, n, largest, swapCount);
    }
}

void heapSort(struct Faculty arr[], int n, int* swapCount) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swapCount);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        (*swapCount)++;
        heapify(arr, i, 0, swapCount);
    }
}

int main() {
    int n;
    printf("Enter the number of faculties: ");
    scanf("%d", &n);

    struct Faculty* faculties = (struct Faculty*)malloc(n * sizeof(struct Faculty));

    for (int i = 0; i < n; i++) {
        printf("\nFaculty %d\n", i + 1);

        printf("Enter faculty name: ");
        scanf(" %[^\n]s", faculties[i].faculty_name);

        printf("Enter faculty ID: ");
        scanf("%d", &faculties[i].faculty_ID);

        printf("Enter subject codes: ");
        scanf(" %[^\n]s", faculties[i].subject_codes);

        printf("Enter class names: ");
        scanf(" %[^\n]s", faculties[i].class_names);
    }

    int swapCount = 0;
    heapSort(faculties, n, &swapCount);

    printf("\nSorted Faculty List:\n");
    for (int i = 0; i < n; i++) {
        printf("Faculty %d\n", i + 1);
        printf("Name: %s\n", faculties[i].faculty_name);
        printf("ID: %d\n", faculties[i].faculty_ID);
        printf("Subject Codes: %s\n", faculties[i].subject_codes);
        printf("Class Names: %s\n\n", faculties[i].class_names);
    }

    printf("Number of swaps performed: %d\n", swapCount);

    free(faculties);

    return 0;
}
