#include <stdio.h>
#include <string.h>

// Define the maximum number of students and hash table size
#define MAX_STUDENTS 100
#define TABLE_SIZE 101

// Define a struct to represent a student
typedef struct {
    char name[50];
    int roll;
    char division[5];
} Student;

// Define the hash table as an array of student pointers
Student* hash_table[TABLE_SIZE];

// Define the hash function as a simple modulo operation
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert a student into the hash table using chaining with linear probing
void insert(Student* student) {
    int index = hash(student->roll);
    int i = 0;
    while (hash_table[(index + i) % TABLE_SIZE] != NULL) {
        i++;
        if (i == TABLE_SIZE) {
            printf("Hash table is full\n");
            return;
        }
    }
    hash_table[(index + i) % TABLE_SIZE] = student;
}

// Search for a student in the hash table using the given roll number
Student* search(int roll) {
    int index = hash(roll);
    int i = 0;
    while (hash_table[(index + i) % TABLE_SIZE] != NULL) {
        if (hash_table[(index + i) % TABLE_SIZE]->roll == roll) {
            return hash_table[(index + i) % TABLE_SIZE];
        }
        i++;
        if (i == TABLE_SIZE) {
            break;
        }
    }
    return NULL;
}

// Test the hash table by inserting some sample students and searching for them
int main() {
    // Insert some sample students
    Student students[MAX_STUDENTS] = {
        {"Alice", 10, "S.E."},
        {"Bob", 11, "S.E."},
        {"Charlie", 12, "T.E."},
        {"Dave", 13, "T.E."},
        {"Eve", 14, "B.E."},
        {"Frank", 15, "B.E."},
        {"Grace", 16, "S.E."},
        {"Harry", 17, "S.E."},
        {"Irene", 18, "T.E."},
        {"John", 19, "T.E."},
    };
    for (int i = 0; i < 10; i++) {
        insert(&students[i]);
    }

    // Search for a student with roll number 17
    Student* result = search(17);
    if (result != NULL) {
        printf("Found student: %s, %d, %s\n", result->name, result->roll, result->division);
    } else {
        printf("Student not found\n");
    }

    return 0;
}



