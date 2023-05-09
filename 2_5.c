#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FACULTIES 10
#define MAX_NAME_LENGTH 20

typedef struct Faculty {
    int id;
    char name[MAX_NAME_LENGTH];
    char subject[MAX_NAME_LENGTH];
    char className[MAX_NAME_LENGTH];
} Faculty;

typedef struct Node {
    Faculty faculty;
    struct Node *next;
} Node;

Node *hashTable[MAX_FACULTIES] = {NULL};

int hashFunction(int id) {
    return id % MAX_FACULTIES;
}

void insertFaculty(Faculty faculty) {
    int key = hashFunction(faculty.id);
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->faculty = faculty;
    newNode->next = NULL;

    if (hashTable[key] == NULL) {
        hashTable[key] = newNode;
    } else {
        Node *temp = hashTable[key];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Faculty searchFaculty(int id) {
    int key = hashFunction(id);
    Node *temp = hashTable[key];
    while (temp != NULL) {
        if (temp->faculty.id == id) {
            return temp->faculty;
        }
        temp = temp->next;
    }
    Faculty nullFaculty = {-1, "", "", ""};
    return nullFaculty;
}

void printHashTable() {
    for (int i = 0; i < MAX_FACULTIES; i++) {
        printf("Key %d: ", i);
        Node *temp = hashTable[i];
        while (temp != NULL) {
            printf("(%d, %s, %s, %s) -> ", temp->faculty.id, temp->faculty.name, temp->faculty.subject, temp->faculty.className);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Faculty faculty1 = {101, "John", "Maths", "Class A"};
    Faculty faculty2 = {102, "David", "Physics", "Class B"};
    Faculty faculty3 = {103, "Lisa", "Chemistry", "Class C"};
    Faculty faculty4 = {104, "Samantha", "Biology", "Class D"};
    Faculty faculty5 = {105, "Robert", "English", "Class E"};

    insertFaculty(faculty1);
    insertFaculty(faculty2);
    insertFaculty(faculty3);
    insertFaculty(faculty4);
    insertFaculty(faculty5);

    printf("Hash Table:\n");
    printHashTable();

    int searchID = 103;
    Faculty foundFaculty = searchFaculty(searchID);
    if (foundFaculty.id != -1) {
        printf("\nFaculty with ID %d found: (%d, %s, %s, %s)\n", searchID, foundFaculty.id, foundFaculty.name, foundFaculty.subject, foundFaculty.className);
    } else {
        printf("\nFaculty with ID %d not found.\n", searchID);
    }

    return 0;
}
