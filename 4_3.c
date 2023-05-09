#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the number of queues: ");
    scanf("%d", &m);

    // allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // initialize array elements
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // calculate size of each queue
    int q_size = n / m;

    // allocate memory for queues
    int **queues = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        queues[i] = (int *)malloc(q_size * sizeof(int));
    }

    // initialize queues
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q_size; j++) {
            queues[i][j] = -1;
        }
    }

    // assign array elements to queues
    int q = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (j == q_size) {
            q++;
            j = 0;
        }
        if (q == m) {
            q = 0;
        }
        queues[q][j] = arr[i];
        j++;
    }

    // print the queues
    for (int i = 0; i < m; i++) {
        printf("Queue %d: ", i + 1);
        for (int j = 0; j < q_size; j++) {
            if (queues[i][j] != -1) {
                printf("%d ", queues[i][j]);
            }
        }
        printf("\n");
    }

    // free memory
    free(arr);
    for (int i = 0; i < m; i++) {
        free(queues[i]);
    }
    free(queues);

    return 0;
}
