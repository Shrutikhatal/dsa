#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FACULTY 100 // maximum number of faculties that can be stored
#define TABLE_SIZE 13 // size of hash table
#define EMPTY_SLOT -1 // value to indicate empty slot in hash table
#define DELETED_SLOT -2 // value to indicate deleted slot in hash table

// structure for faculty record
struct faculty {
    int faculty_id;
    char faculty_name[50];
    char subject_codes[20];
    char class_names[20];
};

// structure for hash table entry
struct hash_entry {
    int status; // status of slot: EMPTY_SLOT, DELETED_SLOT or index of faculty record in faculty_db
    struct faculty f; // faculty record
};

struct hash_entry hash_table[TABLE_SIZE]; // hash table

// function prototypes
void init_hash_table();
void insert_faculty(struct faculty f);
int hash_function(int key);
int linear_probe(int key);
void display_faculty(struct faculty f);
void search_faculty(int faculty_id);

int main() {
    int option, faculty_id;
    struct faculty f;

    // initialize hash table
    init_hash_table();

    do {
        printf("\n1. Insert Faculty\n2. Search Faculty\n3. Exit\nEnter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter faculty details: \n");
                printf("Faculty ID: ");
                scanf("%d", &f.faculty_id);
                printf("Faculty Name: ");
                scanf("%s", f.faculty_name);
                printf("Subject Codes: ");
                scanf("%s", f.subject_codes);
                printf("Class Names: ");
                scanf("%s", f.class_names);
                insert_faculty(f);
                break;
            case 2:
                printf("\nEnter faculty ID to search: ");
                scanf("%d", &faculty_id);
                search_faculty(faculty_id);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid option. Please try again.");
        }
    } while (1);

    return 0;
}
