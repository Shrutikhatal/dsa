#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

typedef struct faculty {
    char name[50];
    int age;
    char dept[50];
    char designation[50];
    float salary;
}Faculty;

int hash(int key) {
    int sq = key * key;
    int hash_val = 0;
    int num = sq;
    int count = 0;
    while (num != 0 && count < 2) {
        hash_val += num % 10;
        num /= 10;
        count++;
    }
    return hash_val % SIZE;
}

void insert(Faculty* hash_table[], Faculty* emp) {
    int key = emp->age;
    int index = hash(key);
    int i = 1;
    while (hash_table[index] != NULL) {
        index = (index + i) % SIZE;
        i++;
    }
    hash_table[index] = emp;
}

void display(Faculty* hash_table[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hash_table[i] != NULL) {
            printf("[%d] -> Name: %s | Age: %d | Department: %s | Designation: %s | Salary: %.2f\n", i, hash_table[i]->name, hash_table[i]->age, hash_table[i]->dept, hash_table[i]->designation, hash_table[i]->salary);
        }
        else {
            printf("[%d] -> NULL\n", i);
        }
    }
}

Faculty* search(Faculty* hash_table[], int key) {
    int index = hash(key);
    int i = 1;
    while (hash_table[index] != NULL) {
        if (hash_table[index]->age == key) {
            return hash_table[index];
        }
        index = (index + i) % SIZE;
        i++;
    }
    return NULL;
}

int main() {
    Faculty* hash_table[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hash_table[i] = NULL;
    }
    Faculty emp1 = { "John Doe", 30, "Computer Science", "Assistant Professor", 50000.00 };
    Faculty emp2 = { "Jane Smith", 35, "Electronics", "Associate Professor", 60000.00 };
    Faculty emp3 = { "David Johnson", 40, "Mechanical", "Professor", 70000.00 };
    Faculty emp4 = { "Maria Garcia", 45, "Civil", "Associate Professor", 60000.00 };
    Faculty emp5 = { "Robert Lee", 50, "Chemical", "Professor", 80000.00 };
    insert(hash_table, &emp1);
    insert(hash_table, &emp2);
    insert(hash_table, &emp3);
    insert(hash_table, &emp4);
    insert(hash_table, &emp5);
    display(hash_table);
    int key;
    printf("\nEnter the age to search: ");
    scanf("%d", &key);
    Faculty* emp = search(hash_table, key);
    if (emp != NULL) {
        printf("\nEmployee found!\nName: %s | Age: %d | Department: %s | Designation: %s | Salary: %.2f\n", emp->name, emp->age, emp->dept, emp->designation, emp->salary);
}
else {
    printf("\nEmployee not found!\n");
}
return 0;}
