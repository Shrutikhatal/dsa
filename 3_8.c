#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Stack definition
struct Stack {
    int top;
    int items[MAX_STACK_SIZE];
};

// Stack operations
void push(struct Stack* s, int x) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = x;
}

int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int peek(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->items[s->top];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Helper function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert postfix expression to prefix expression
char* postfixToPrefix(char* postfix) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;

    int i, j;
    char ch, temp[2];
    char* prefix = (char*) malloc(strlen(postfix) * sizeof(char));

    for (i = 0, j = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            temp[0] = ch;
            temp[1] = '\0';
            strcat(prefix, temp);
        } else if (isOperator(ch)) {
            char op1 = pop(stack);
            char op2 = pop(stack);
            prefix[j++] = ch;
            prefix[j++] = op2;
            prefix[j++] = op1;
            push(stack, ch);
        } else {
            push(stack, ch);
        }
    }

    prefix[j] = '\0';
    return prefix;
}

// Evaluate prefix expression using stack
int evaluatePrefix(char* prefix) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;

    int i, op1, op2, result;
    char ch;

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        ch = prefix[i];

        if (isdigit(ch)) {
            push(stack, ch - '0');
        } else if (isOperator(ch)) {
            op1 = pop(stack);
            op2 = pop(stack);

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = op1 ^ op2; break;
            }

            push(stack, result);
        }
    }

    return pop(stack);
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    char* prefix = postfixToPrefix(postfix);
    printf("Prefix expression: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result %s\n",result);
    return 0;
}
