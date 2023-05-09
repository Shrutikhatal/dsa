#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x, y;
};

// Function to compute the distance between two points
float distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to compare two points based on their x-coordinates
int cmpX(const void *a, const void *b) {
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    return p1->x - p2->x;
}

// Function to find the closest pair of points
struct Point* closestPair(struct Point arr[], int n) {
    // Sort the points based on their x-coordinates
    qsort(arr, n, sizeof(struct Point), cmpX);

    // Initialize variables to store the minimum distance and the closest pair of points
    float minDist = distance(arr[0], arr[1]);
    struct Point *minPair = malloc(2 * sizeof(struct Point));
    minPair[0] = arr[0];
    minPair[1] = arr[1];

    // Traverse the sorted set of points from left to right
    for (int i = 0; i < n - 1; i++) {
        // Compute the distance between the current point and its neighbor(s) to the right
        for (int j = i + 1; j < n; j++) {
            float dist = distance(arr[i], arr[j]);
            // Update minDist and minPair if a closer pair of points is found
            if (dist < minDist) {
                minDist = dist;
                minPair[0] = arr[i];
                minPair[1] = arr[j];
            }
        }
    }

    return minPair;
}

int main() {
    // Example set of points
    struct Point arr[] = {{1, 2}, {3, 4}, {6, 8}, {4, 6}, {7, 9}, {9, 12}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the closest pair of points
    struct Point *minPair = closestPair(arr, n);

    // Print the closest pair of points
    printf("Closest pair of points: (%d, %d), (%d, %d)\n", minPair[0].x, minPair[0].y, minPair[1].x, minPair[1].y);

    free(minPair); // Free the memory allocated for minPair

    return 0;
}
