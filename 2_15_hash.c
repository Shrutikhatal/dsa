#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 100

// Structure for the hash table entry
typedef struct {
    int key;
    bool isOccupied;
} HashEntry;

// Function to compute the hash value using modulo operator
int hash(int key, int tableSize) {
    return key % tableSize;
}

// Function to insert an element into the hash table
void insertIntoHashTable(int element, HashEntry* hashTable, int tableSize) {
    int hashValue = hash(element, tableSize);
    int index = hashValue;

    while (hashTable[index].isOccupied) {
        index = (index + 1) % tableSize;
    }

    hashTable[index].key = element;
    hashTable[index].isOccupied = true;
}

// Function to check if set S is a subset of set T
bool isSubset(int* S, int m, int* T, int n) {
    // Create a hash table of size m
    HashEntry* hashTable = (HashEntry*) malloc(TABLE_SIZE * sizeof(HashEntry));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = false;
    }

    // Insert elements from set S into the hash table
    for (int i = 0; i < m; i++) {
        insertIntoHashTable(S[i], hashTable, TABLE_SIZE);
    }

    // Check if each element in set T is present in the hash table
    for (int i = 0; i < n; i++) {
        int hashValue = hash(T[i], TABLE_SIZE);
        int index = hashValue;

        while (hashTable[index].isOccupied) {
            if (hashTable[index].key == T[i]) {
                break;  // Element found in the hash table
            }
            index = (index + 1) % TABLE_SIZE;
        }

        if (!hashTable[index].isOccupied || hashTable[index].key != T[i]) {
            return false;  // Element not found in the hash table
        }
    }

    return true;  // All elements in set T found in the hash table
}

int main() {
    int m, n;

    printf("Enter the number of elements in set S: ");
    scanf("%d", &m);

    printf("Enter the number of elements in set T: ");
    scanf("%d", &n);

    int* S = (int*) malloc(m * sizeof(int));
    int* T = (int*) malloc(n * sizeof(int));

    printf("Enter the elements of set S: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &S[i]);
    }

    printf("Enter the elements of set T: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
    }

    bool isSubsetResult = isSubset(S, m, T, n);
    if (isSubsetResult) {
        printf("S is a subset of T\n");
    } else {
        printf("S is not a subset of T\n");
    }

    free(S);
    free(T);

    return 0;
}
