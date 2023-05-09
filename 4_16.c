#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n, m, i, j, k, item, queue_count = 0;
    int queue[MAX_SIZE][MAX_SIZE];
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int array[n];
    
    printf("Enter the elements of array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Enter the number of queues: ");
    scanf("%d", &m);
    
    int queue_size = n / m;
    
    if (n % m != 0) {
        queue_size++;
    }
    
    for (i = 0; i < n; i++) {
        k = i / queue_size;
        j = i % queue_size;
        
        if (j == 0 && i != 0) {
            queue_count++;
        }
        
        queue[queue_count][j] = array[i];
    }
    
    printf("Queues after division of array:\n");
    for (i = 0; i <= queue_count; i++) {
        printf("Queue %d: ", i+1);
        
        for (j = 0; j < queue_size && (i*queue_size+j) < n; j++) {
            printf("%d ", queue[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}
