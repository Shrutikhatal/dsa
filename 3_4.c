#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack structure
struct Stack {
   int top;
   int capacity;
   char* array;
};

// Create a new stack with given capacity
struct Stack* createStack(int capacity) {
   struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
   stack->top = -1;
   stack->capacity = capacity;
   stack->array = (char*) malloc(stack->capacity * sizeof(char));
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
void push(struct Stack* stack, char item) {
   if (isFull(stack)) {
      printf("Stack overflow\n");
      return;
   }
   stack->array[++stack->top] = item;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
   if (isEmpty(stack)) {
      printf("Stack underflow\n");
      return '\0';
   }
   return stack->array[stack->top--];
}

// Check if a string is a palindrome using stack
int isPalindrome(char* str) {
   int len = strlen(str);
   struct Stack* stack = createStack(len);
   for (int i = 0; i < len; i++) {
      push(stack, str[i]);
   }
   for (int i = 0; i < len; i++) {
      if (pop(stack) != str[i]) {
         free(stack->array);
         free(stack);
         return 0;
      }
   }
   free(stack->array);
   free(stack);
   return 1;
}

// Reverse a string using stack
char* reverseString(char* str) {
   int len = strlen(str);
   struct Stack* stack = createStack(len);
   for (int i = 0; i < len; i++) {
      push(stack, str[i]);
   }
   char* revStr = (char*) malloc(len * sizeof(char));
   for (int i = 0; i < len; i++) {
      revStr[i] = pop(stack);
   }
   revStr[len] = '\0';
   free(stack->array);
   free(stack);
   return revStr;
}

// Concatenate two strings using stack
char* concatenateStrings(char* str1, char* str2) {
   int len1 = strlen(str1);
   int len2 = strlen(str2);
   struct Stack* stack = createStack(len1 + len2);
   for (int i = 0; i < len1; i++) {
      push(stack, str1[i]);
   }
   for (int i = 0; i < len2; i++) {
      push(stack, str2[i]);
   }
   char* concatStr = (char*) malloc((len1 + len2) * sizeof(char));
   for (int i = 0; i < len1 + len2; i++) {
      concatStr[i] = pop(stack);
   }
   concatStr[len1 + len2] = '\0';
   free(stack->array);
   free(stack);
   return concatStr;
}

// Compare two strings using stack
// Compare two strings using stack
int compareStrings(char* str1, char* str2) {
   int len1 = strlen(str1);
   int len2 = strlen(str2);
   if (len1 != len2) {
      return 0;
   }
   struct Stack* stack1 = createStack(len1);
   struct Stack* stack2 = createStack(len2);
   for (int i = 0; i < len1; i++) {
      push(stack1, str1[i]);
   }
   for (int i = 0; i < len2; i++) {
      push(stack2, str2[i]);
   }
   int isSame = 1;
   for (int i = 0; i < len1; i++) {
      if (pop(stack1) != pop(stack2)) {
         isSame = 0;
         break;
      }
   }
   free(stack1->array);
   free(stack1);
   free(stack2->array);
   free(stack2);
   return isSame;
}

int main() {
   char str[50], str1[50], str2[50];
   printf("Enter a string: ");
   fgets(str, 50, stdin);
   // Remove newline character from input
   str[strcspn(str, "\n")] = 0;
   printf("String: %s\n", str);
   // Check if the string is palindrome
   if (isPalindrome(str)) {
      printf("The string is a palindrome.\n");
   } else {
      printf("The string is not a palindrome.\n");
   }
   // Reverse the string
   char* revStr = reverseString(str);
   printf("Reverse of the string: %s\n", revStr);
   free(revStr);
   // Concatenate two strings
   printf("Enter another string: ");
   fgets(str1, 50, stdin);
   str1[strcspn(str1, "\n")] = 0;
   char* concatStr = concatStrings(str, str1);
   printf("Concatenated string: %s\n", concatStr);
   free(concatStr);
   // Compare two strings
   printf("Enter another string to compare with the first string: ");
   fgets(str2, 50, stdin);
   str2[strcspn(str2, "\n")] = 0;
   if (compareStrings(str, str2)) {
      printf("Both strings are same.\n");
   } else {
      printf("Both strings are different.\n");
   }
   return 0;
}
