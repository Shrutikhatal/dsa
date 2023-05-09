
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Non-recursive Preorder traversal
void preOrder(struct Node* root) {
    // Create a stack for storing nodes
    struct Node* stack[100];
    int top = -1;
 
    // Push the root node onto the stack
    stack[++top] = root;
 
    // Loop until stack is empty
    while (top >= 0) {
        // Pop the top node from the stack and print its data
        struct Node* temp_node = stack[top--];
        printf("%d ", temp_node->data);
 
        // Push the right child onto the stack if it exists
        if (temp_node->right)
            stack[++top] = temp_node->right;
 
        // Push the left child onto the stack if it exists
        if (temp_node->left)
            stack[++top] = temp_node->left;
    }
}

// Non-recursive Postorder traversal
void postOrder(struct Node* root) {
    // Create two stacks for storing nodes
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;
 
    // Push the root node onto stack 1
    stack1[++top1] = root;
 
    // Loop until stack 1 is empty
    while (top1 >= 0) {
        // Pop the top node from stack 1 and push it onto stack 2
        struct Node* temp_node = stack1[top1--];
        stack2[++top2] = temp_node;
 
        // Push the left and right children onto stack 1 if they exist
        if (temp_node->left)
            stack1[++top1] = temp_node->left;
        if (temp_node->right)
            stack1[++top1] = temp_node->right;
    }
 
    // Print the nodes from stack 2
    while (top2 >= 0) {
        struct Node* temp_node = stack2[top2--];
        printf("%d ", temp_node->data);
    }
}

int main() {
    // Create the binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    // Perform preorder and postorder traversals
    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
