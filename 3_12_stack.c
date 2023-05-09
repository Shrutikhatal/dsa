#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int main() {
    int n, m;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the number of stacks to divide the array into (2 < m < n): ");
    scanf("%d", &m);

    if (m < 3 || m >= n) {
        printf("Invalid value of m!\n");
        return 0;
    }

    int* array = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &array[i]);
    }

    int stack_capacity = n / m;
    struct Stack** stacks = (struct Stack**) malloc(m * sizeof(struct Stack*));

    for (int i = 0; i < m; i++) {
        stacks[i] = createStack(stack_capacity);
    }

    int stack_index = 0;
    for (int i = 0; i < n; i++) {
        if (isFull(stacks[stack_index])) {
            if (stack_index == m - 1) {
                printf("All stacks are full!\n");
                break;
            }
            if (!isFull(stacks[stack_index + 1])) {
                stack_index++;
            }
        }
        push(stacks[stack_index], array[i]);
    }

    printf("Contents of the stacks:\n");
    for (int i = 0; i < m; i++) {
        printf("Stack %d: ", i + 1);
        while (!isEmpty(stacks[i])) {
            printf("%d ", pop(stacks[i]));
        }
        printf("\n");
    }

    return 0;
}
