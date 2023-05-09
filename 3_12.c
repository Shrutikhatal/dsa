#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// function to push element in the stack
void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full.\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// function to pop element from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int main() {
    int n, m;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the number of stacks: ");
    scanf("%d", &m);

    // create an array of stacks
    Stack *stacks = (Stack *) malloc(m * sizeof(Stack));

    // perform push and pop operations on each stack
    for (int i = 0; i < m; i++) {
        printf("Stack %d:\n", i);
        for (int j = 0; j < n / m; j++) {
            int value;
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stacks[i], value);
        }
        while (stacks[i].top != -1) {
            int value = pop(&stacks[i]);
            printf("Popped value: %d\n", value);
        }
    }

    free(stacks);
    return 0;
}
