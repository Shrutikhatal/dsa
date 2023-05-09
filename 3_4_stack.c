#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE];

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        return '\0';
    }
    char c = stack[top];
    top--;
    return c;
}

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

void concatenateString(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i < len2; i++) {
        push(s2[i]);
    }
    for (int i = 0; i < len1; i++) {
        push(s1[i]);
    }
    int i = 0;
    while (top != -1) {
        s1[i] = pop();
        i++;
    }
    s1[i] = '\0';
}

int compareStrings(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = len1 < len2 ? len1 : len2;
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return len1 - len2;
}

int main() {
    char string[MAX_SIZE], string2[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", string);

    if (isPalindrome(string)) {
        printf("%s is a palindrome\n", string);
    } else {
        printf("%s is not a palindrome\n", string);
    }

    reverseString(string);
    printf("Reversed string: %s\n", string);

    printf("Enter another string to concatenate with %s: ", string);
    scanf("%s", string2);
    concatenateString(string, string2);
    printf("Concatenated string: %s\n", string);

     printf("Enter a string to compare with %s: ", string);
    scanf("%s", string2);
    int result = compareStrings(string, string2);
    if (result == 0) {
        printf("%s is equal to %s\n", string, string2);
    } else if (result < 0) {
        printf("%s is less than %s\n", string, string2);
    } else {
        printf("%s is greater than %s\n", string, string2);
    }

    return 0;
}
