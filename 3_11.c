#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
   int top;
   int capacity;
   int* array;
};

// Create a new stack with given capacity
struct Stack* createStack(int capacity) {
   struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
   stack->top = -1;
   stack->capacity = capacity;
   stack->array = (int*) malloc(stack->capacity * sizeof(int));
   return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
   return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
   return stack->top == stack->capacity - 1;
}

// Push an element onto the stack
void push(struct Stack* stack, int item) {
   if (isFull(stack)) {
      printf("Stack overflow\n");
      return;
   }
   stack->array[++stack->top] = item;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
   if (isEmpty(stack)) {
      printf("Stack underflow\n");
      return -1;
   }
   return stack->array[stack->top--];
}
// The decimalToBinary() function converts a decimal number to binary using a stack by repeatedly dividing the decimal number by 2 and pushing the remainder onto the stack. Then, it pops all the elements off the stack and prints "Move to next room" if the popped element is 1 and "Stay in current room" if the popped element is 0.
// Convert a decimal number to binary using stack
void decimalToBinary(int decimal) {
   struct Stack* stack = createStack(10);
   while (decimal > 0) {
      push(stack, decimal % 2);
      decimal /= 2;
   }
   while (!isEmpty(stack)) {
      int binary = pop(stack);
      if (binary == 1) {
         printf("Move to next room\n");
      } else {
         printf("Stay in current room\n");
      }
   }
   free(stack->array);
   free(stack);
}

int main() {
   int decimal;
   printf("Enter the decimal number written in the box in last room: ");
   scanf("%d", &decimal);
   decimalToBinary(decimal);
   printf("Open the treasure in first room\n");
   return 0;
}
