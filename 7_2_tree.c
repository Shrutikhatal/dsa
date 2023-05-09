#include <stdio.h>
#include <stdlib.h>

// Binary Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        }
        else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to perform levelwise display of the binary tree
void levelwiseDisplay(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* queue[1000];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

// Function to perform mirror image of the binary tree
void mirrorImage(struct Node* root) {
    if(root==NULL) return;
    struct node* temp=root->left;
    root->left=root->right;
    mirror(root->left);
    mirror(root->right);
}

// Function to display the height of the binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else {
            return rightHeight + 1;
        }
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data;
    while (1) {
        printf("\n1. Insert node");
        printf("\n2. Levelwise display");
        printf("\n3. Mirror image");
        printf("\n4. Display height");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("\nLevelwise display: ");
            levelwiseDisplay(root);
            break;
        case 3:
            printf("\nMirror image: ");
            mirrorImage(root);
            levelwiseDisplay(root);
            break;
        case 4:
            printf("\nHeight of the binary tree: %d", height(root));
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice!");
            break;
        }
    }
    return 0;
}
