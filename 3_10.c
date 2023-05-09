#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

// Structure for stack
struct stack {
    int top;
    char items[MAX];
};

// Function to initialize stack
void initialize(struct stack *s) {
    s->top = -1;
}

// Function to check if stack is full
int isFull(struct stack *s) {
    return s->top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty(struct stack *s) {
    return s->top == -1;
}

// Function to push an element onto stack
void push(struct stack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = item;
}

// Function to pop an element from stack
char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to evaluate the given postfix expression
int evaluatePostfix(char *exp) {
    struct stack s;
    initialize(&s);
    int i, operand1, operand2, result;
    char ch;

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch(ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

// Function to convert the given postfix expression into infix expression
void postfixToInfix(char *postfix, char *infix) {
    struct stack s;
    initialize(&s);
    int i, j;
    char ch;

    for (i = 0, j = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            infix[j++] = ch;
        } else {
            char op1 = pop(&s);
            char op2 = pop(&s);
            infix[j++] = '(';
            infix[j++] = op2;
            infix[j++] = ch;
            infix[j++] = op1;
            infix[j++] = ')';
            push(&s, infix[j - 2]);
        }
    }
    infix[j] = '\0';
}

int main() {
    char postfix[MAX], infix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix, infix);
    printf("Infix expression: %s\n", infix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}
