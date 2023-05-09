#include <stdio.h>

#define MAX_SIZE 100 // maximum size of the array
#define MAX_STACKS 5 // maximum number of stacks to be implemented

int arr[MAX_SIZE]; // array to hold the stacks
int top[MAX_STACKS]; // array to hold the top index of each stack
int stackSize[MAX_STACKS]; // array to hold the size of each stack
int totalStacks = 0; // total number of stacks in use

// function to check if a stack is full
int isStackFull(int stackNum) {
  return top[stackNum] == stackSize[stackNum] - 1;
}

// function to check if a stack is empty
int isStackEmpty(int stackNum) {
  return top[stackNum] == -1;
}

// function to push an element onto a stack
void push(int stackNum, int data) {
  if (isStackFull(stackNum)) {
    printf("Stack %d is full.\n", stackNum);
  } else {
    top[stackNum]++;
    arr[top[stackNum] + stackNum*MAX_SIZE] = data;
    printf("Pushed %d onto Stack %d.\n", data, stackNum);
  }
}

// function to pop an element from a stack
int pop(int stackNum) {
  if (isStackEmpty(stackNum)) {
    printf("Stack %d is empty.\n", stackNum);
    return -1;
  } else {
    int data = arr[top[stackNum] + stackNum*MAX_SIZE];
    top[stackNum]--;
    printf("Popped %d from Stack %d.\n", data, stackNum);
    return data;
  }
}

// function to display a stack
void display(int stackNum) {
  if (isStackEmpty(stackNum)) {
    printf("Stack %d is empty.\n", stackNum);
  } else {
    printf("Stack %d: ", stackNum);
    for (int i = top[stackNum] + stackNum*MAX_SIZE; i >= stackNum*MAX_SIZE; i--) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
}

int main() {
  // initialize all stacks to be empty
  for (int i = 0; i < MAX_STACKS; i++) {
    top[i] = -1;
  }
  
  // example usage
  totalStacks = 3;
  stackSize[0] = 5; // set size of stack 0 to be 5
  stackSize[1] = 3; // set size of stack 1 to be 3
  stackSize[2] = 2; // set size of stack 2 to be 2
  
  push(0, 1);
  push(0, 2);
  push(0, 3);
  push(0, 4);
  push(0, 5);
  push(0, 6); // should output "Stack 0 is full."
  
  push(1, 10);
  push(1, 20);
  push(1, 30);
  push(1, 40); // should output "Stack 1 is full."
  
  push(2, 100);
  push(2, 200);
  
  pop(0); // should output "Popped 5 from Stack 0."
  
  display(0); // should output "Stack 0:
return 0;
}