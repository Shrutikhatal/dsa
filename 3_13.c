#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack implementation for integer values
struct Stack {
   int top;
   unsigned capacity;
   int* array;
};

// Function to create a stack of given size
struct Stack* createStack(int size) {
   struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
   stack->capacity = size;
   stack->top = -1;
   stack->array = (int*) malloc(stack->capacity * sizeof(int));
   return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
   return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
   return stack->top == stack->capacity - 1;
}

// Function to push a value onto the stack
void push(struct Stack* stack, int value) {
   if (isFull(stack)) {
      printf("Stack Overflow\n");
      return;
   }
   stack->array[++stack->top] = value;
}

// Function to pop a value from the stack
int pop(struct Stack* stack) {
   if (isEmpty(stack)) {
      printf("Stack Underflow\n");
      return -1;
   }
   return stack->array[stack->top--];
}

// Function to calculate the factorial of a number using stack
int factorial(int n) {
   if (n < 0) {
      printf("Factorial of negative numbers is not defined.\n");
      return -1;
   }
   struct Stack* stack = createStack(MAX_SIZE);
   push(stack, 1);
   int result = 1;
   for (int i = 2; i <= n; i++) {
      push(stack, i);
   }
   while (!isEmpty(stack)) {
      result *= pop(stack);
   }
   free(stack->array);
   free(stack);
   return result;
}

// Function to generate the Fibonacci series using stack
void fibonacci(int n) {
   if (n <= 0) {
      printf("Invalid input.\n");
      return;
   }
   struct Stack* stack = createStack(MAX_SIZE);
   push(stack, 0);
   if (n >= 1) {
      push(stack, 1);
   }
   int a, b, c;
   while (n-- >= 2) {
      b = pop(stack);
      a = pop(stack);
      c = a + b;
      push(stack, b);
      push(stack, c);
   }
   printf("Fibonacci Series: ");
   while (!isEmpty(stack)) {
      printf("%d ", pop(stack));
   }
   printf("\n");
   free(stack->array);
   free(stack);
}

int main() {
   int n;
   printf("Enter a number to find its factorial: ");
   scanf("%d", &n);
   int fact = factorial(n);
   if (fact != -1) {
      printf("Factorial of %d is %d\n", n, fact);
   }
   printf("Enter a number to generate the Fibonacci series: ");
   scanf("%d", &n);
   fibonacci(n);
   return 0;
}
