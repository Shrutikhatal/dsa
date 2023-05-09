#include <stdio.h>
#include <string.h>
#define SIZE 10

struct faculty {
    char name[20];
    char department[20];
    char designation[20];
    char phone[12];
};

struct faculty faculties[SIZE];

void insert(struct faculty f) {
    int key = strlen(f.name) % SIZE;
    int i = key;
    do {
        if (faculties[i].name[0] == '\0') {
            faculties[i] = f;
            return;
        }
        i = (i + 1) % SIZE;
    } while (i != key);
    printf("Hash table is full\n");
}

void search(char name[]) {
    int key = strlen(name) % SIZE;
    int i = key;
    do {
        if (strcmp(faculties[i].name, name) == 0) {
            printf("Name: %s\nDepartment: %s\nDesignation: %s\nPhone: %s\n", faculties[i].name, faculties[i].department, faculties[i].designation, faculties[i].phone);
            return;
        }
        i = (i + 1) % SIZE;
    } while (i != key && faculties[i].name[0] != '\0');

    // If the loop went all the way around and returned to the original key,
    // check if the faculty member was found or not
    if (strcmp(faculties[i].name, name) != 0) {
        printf("Faculty not found\n");
    }
}

int main() {
    struct faculty f1 = {"John Doe", "Computer Science", "Professor", "555-1234"};
    struct faculty f2 = {"Jane Smith", "Mathematics", "Associate Professor", "555-5678"};
    struct faculty f3 = {"Bob Johnson", "Physics", "Assistant Professor", "555-9012"};
    insert(f1);
    insert(f2);
    insert(f3);
    char name[20];
    printf("Enter name to search: ");
    scanf("%s", name);
    search(name);
    return 0;
}
