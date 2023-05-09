#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct node {
    int key;
    int value;
    struct node* next;
};

struct node* hashTable[MAX];

void init() {
    int i;
    for(i = 0; i < MAX; i++) {
        hashTable[i] = NULL;
    }
}

void insert(int key, int value) {
    int hashIndex = key % MAX;
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if(hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newNode;
    } else {
        struct node* currNode = hashTable[hashIndex];
        while(currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}

void display() {
    int i;
    for(i = 0; i < MAX; i++) {
        printf("Index %d: ", i);
        if(hashTable[i] == NULL) {
            printf("NULL\n");
        } else {
            struct node* currNode = hashTable[i];
            while(currNode != NULL) {
                printf("(%d, %d) ", currNode->key, currNode->value);
                currNode = currNode->next;
            }
            printf("\n");
        }
    }
}

int search(int key) {
    int hashIndex = key % MAX;
    if(hashTable[hashIndex] == NULL) {
        return -1;
    } else {
        struct node* currNode = hashTable[hashIndex];
        while(currNode != NULL) {
            if(currNode->key == key) {
                return currNode->value;
            }
            currNode = currNode->next;
        }
        return -1;
    }
}

int delete(int key) {
    int hashIndex = key % MAX;
    if(hashTable[hashIndex] == NULL) {
        return -1;
    } else {
        struct node* currNode = hashTable[hashIndex];
        struct node* prevNode = NULL;
        while(currNode != NULL) {
            if(currNode->key == key) {
                if(prevNode == NULL) {
                    hashTable[hashIndex] = currNode->next;
                } else {
                    prevNode->next = currNode->next;
                }
                free(currNode);
                return 1;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }
        return -1;
    }
}

int main() {
    init();
    insert(1, 10);
    insert(11, 20);
    insert(21, 30);
    insert(2, 40);
    insert(22, 50);
    insert(3, 60);
    display();
    printf("Search value for key 21: %d\n", search(21));
    printf("Delete key 21: %d\n", delete(21));
    printf("After deletion:\n");
    display();
    return 0;
}
