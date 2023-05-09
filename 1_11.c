#include <stdio.h>
#include <stdlib.h>

// Function to find the best repair schedule and calculate the total lost service-times
void find_best_schedule(int n, int* repair_times, int* sorted_cars, int* total_lost_time) {
    // sort the cars by their repair times
    for (int i = 0; i < n; i++) {
        sorted_cars[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (repair_times[sorted_cars[i]] > repair_times[sorted_cars[j]]) {
                int temp = sorted_cars[i];
                sorted_cars[i] = sorted_cars[j];
                sorted_cars[j] = temp;
            }
        }
    }
    
    // calculate the total lost service-times
    *total_lost_time = 0;
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        current_time += repair_times[sorted_cars[i]];
        *total_lost_time += current_time;
    }
}

// Example usage
int main() {
    int n = 5;
    int repair_times[] = {3, 7, 1, 5, 2};
    int* sorted_cars = (int*) malloc(n * sizeof(int));
    int total_lost_time;
    
    find_best_schedule(n, repair_times, sorted_cars, &total_lost_time);
    
    printf("Sorted order of repairs: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_cars[i]);
    }
    printf("\nTotal lost service-times: %d\n", total_lost_time);
    
    free(sorted_cars);
    return 0;
}
