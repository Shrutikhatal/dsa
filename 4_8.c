#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int id;
    char name[50];
} Patient;

typedef struct {
    Patient queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Clinic;

void initClinic(Clinic* clinic) {
    clinic->front = 0;
    clinic->rear = -1;
    clinic->size = 0;
}

bool isFull(Clinic* clinic) {
    return clinic->size == MAX_QUEUE_SIZE;
}

bool isEmpty(Clinic* clinic) {
    return clinic->size == 0;
}

void enqueue(Clinic* clinic, Patient patient) {
    if (isFull(clinic)) {
        printf("Clinic is full. Cannot add more patients.\n");
        return;
    }
    clinic->rear = (clinic->rear + 1) % MAX_QUEUE_SIZE;
    clinic->queue[clinic->rear] = patient;
    clinic->size++;
}

Patient dequeue(Clinic* clinic) {
    if (isEmpty(clinic)) {
        printf("Clinic is empty. No patients to remove.\n");
        Patient p = {-1, ""};
        return p;
    }
    Patient patient = clinic->queue[clinic->front];
    clinic->front = (clinic->front + 1) % MAX_QUEUE_SIZE;
    clinic->size--;
    return patient;
}

void printClinic(Clinic* clinic) {
    if (isEmpty(clinic)) {
        printf("Clinic is empty.\n");
        return;
    }
    printf("Patients in the clinic:\n");
    for (int i = clinic->front; i <= clinic->rear; i++) {
        printf("%d. %s\n", clinic->queue[i].id, clinic->queue[i].name);
    }
}

int main() {
    Clinic clinic;
    initClinic(&clinic);

    int option = 0;
    do {
        printf("\n");
        printf("1. Add patient\n");
        printf("2. Assign patient to doctor\n");
        printf("3. View patients in clinic\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                Patient p;
                printf("Enter patient ID: ");
                scanf("%d", &p.id);
                printf("Enter patient name: ");
                scanf("%s", p.name);
                enqueue(&clinic, p);
                break;
            }
            case 2: {
                Patient p = dequeue(&clinic);
                if (p.id != -1) {
                    printf("Assigning patient %d, %s to doctor.\n", p.id, p.name);
                }
                break;
            }
            case 3: {
                printClinic(&clinic);
                break;
            }
            case 4: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid option. Try again.\n");
                break;
            }
        }
    } while (option != 4);

    return 0;
}
