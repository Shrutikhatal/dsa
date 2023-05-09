#include <stdio.h>

#define NUM_COMPUTERS 15
#define NUM_STUDENTS 14
#define NUM_NEW_STUDENTS 3

int assignComputer(int studentNumber) {
    int computerNumber = (studentNumber % NUM_COMPUTERS) + 35;
    return computerNumber;
}

void allocateComputers(int computers[], int numStudents) {
    int i, j;
    for (i = 0; i < numStudents; i++) {
        int studentNumber;
        printf("Enter registration number of student %d: ", i+1);
        scanf("%d", &studentNumber);

        int computerNumber = assignComputer(studentNumber);

        // Linear probing with replacement
        if (computers[computerNumber - 35] != 0) {
            // Computer already allocated, find the next available computer
            for (j = computerNumber - 35 + 1; j < NUM_COMPUTERS; j++) {
                if (computers[j] == 0) {
                    computerNumber = j + 35;
                    break;
                }
            }
        }

        // Allocate the computer to the student
        computers[computerNumber - 35] = studentNumber;
        printf("Student %d allocated computer %d\n", studentNumber, computerNumber);
    }
}

int main() {
    int computers[NUM_COMPUTERS] = {0}; // Initialize all computers to 0 (unallocated)

    printf("Allocating computers for current batch students...\n");
    allocateComputers(computers, NUM_STUDENTS);

    printf("\n");

    printf("Additional batch students want to use computers...\n");
    allocateComputers(computers, NUM_NEW_STUDENTS);

    return 0;
}
