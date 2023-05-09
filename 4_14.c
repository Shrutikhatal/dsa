#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, x, count = 0;
    printf("Enter the number of soldiers: ");
    scanf("%d", &n);
    int *soldiers = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        soldiers[i] = i + 1;
    }
    printf("Enter the value of m (m < n): ");
    scanf("%d", &m);
    printf("Enter the index of the soldier to start counting from (0-based index): ");
    scanf("%d", &x);
    x %= n; // Ensure x is within range
    while (n > 1) {
        x = (x + m - 1) % n; // Find the next soldier to be removed
        printf("Soldier %d is out of the game.\n", soldiers[x]);
        // Remove the soldier from the array
        for (i = x; i < n - 1; i++) {
            soldiers[i] = soldiers[i + 1];
        }
        n--; // Decrement the number of soldiers remaining
    }
    printf("Soldier %d is the last one remaining and will go seek help.\n", soldiers[0]);
    free(soldiers);
    return 0;
}
