#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    char value = s->data[s->top];
    s->top--;
    return value;
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

void reverse(char str[]) {
    int length = strlen(str);
    Stack s;
    initialize(&s);

    for (int i = 0; i < length; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < length; i++) {
        str[i] = pop(&s);
    }
}

void rearrangeName(char name[]) {
    int length = strlen(name);
    Stack s;
    initialize(&s);
    char surname[MAX], firstname[MAX], middlename[MAX];
    int i = length - 1, j = 0;

    while (name[i] != ' ') {
        surname[j] = name[i];
        i--;
        j++;
    }
    surname[j] = '\0';
    reverse(surname);

    j = 0;
    i--;
    while (name[i] != ' ') {
        middlename[j] = name[i];
        i--;
        j++;
    }
    middlename[j] = '\0';
    reverse(middlename);

    j = 0;
    i--;
    while (i >= 0) {
        firstname[j] = name[i];
        i--;
        j++;
    }
    firstname[j] = '\0';
    reverse(firstname);

    strcpy(name, surname);
    strcat(name, " ");
    strcat(name, firstname);
    strcat(name, " ");
    strcat(name, middlename);
}

int main() {
    char name[MAX];
    printf("Enter your name in the format First name Middle name Surname: ");
    fgets(name, MAX, stdin);
    int length = strlen(name);
    if (name[length - 1] == '\n') {
        name[length - 1] = '\0';
    }
    rearrangeName(name);
    printf("Your name in the format Surname First name Middle name: %s\n", name);
    return 0;
}
