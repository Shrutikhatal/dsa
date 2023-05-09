#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 20

typedef struct Node {
    int key;
    struct Node* next;
} Node;

void insert(Node** hash_table, int key, int n) {
    int index = key % n;
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;

    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        Node* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void linear_probing_with_chaining(int* keys, int k, int n) {
    Node** hash_table = (Node**) malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        hash_table[i] = NULL;
    }

    for (int i = 0; i < k; i++) {
        insert(hash_table, keys[i], n);
    }

    printf("Linear probing with chaining:\n");
    for (int i = 0; i < n; i++) {
        printf("Slot %d: ", i);
        Node* current = hash_table[i];
        while (current != NULL) {
            printf("%d ", current->key);
            current = current->next;
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        Node* current = hash_table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table);
}

void rehashing(int* keys, int k, int n) {
    int m = k + 1;
    while (m <= 2 * n) {
        int* new_keys = (int*) malloc(m * sizeof(int));
        for (int i = 0; i < k; i++) {
            new_keys[i] = keys[i];
        }

        int* hash_table = (int*) malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) {
            hash_table[i] = -1;
        }

        for (int i = 0; i < k; i++) {
            int index = new_keys[i] % m;
            if (hash_table[index] == -1) {
                hash_table[index] = new_keys[i];
            } else {
                int j = index;
                while (hash_table[j] != -1) {
                    j = (j + 1) % m;
                }
                hash_table[j] = new_keys[i];
            }
        }

        int collision_count = 0;
        for (int i = 0; i < m; i++) {
            if (hash_table[i] == -1) {
                collision_count++;
            }
        }

        printf("Rehashing with m=%d:\n", m);
        printf("Collision count: %d\n", collision_count);

        free(new_keys);
        free(hash_table);

        m++;
    }
}

int main() {
    int keys[MAX_KEYS] = {21, 42, 63, 84, 105, 126, 147, 168, 189, 210, 231, 252, 273, 294, 315, 336, 357, 378, 399, 420};
    int k = sizeof(keys) / sizeof(keys[0]);
    int n = 10;

    linear_probing_with_chaining(keys, k, n);
    printf("\n");

    rehashing(keys, k, n);

    return 0;
}
