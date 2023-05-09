/*Write a Program to create Inorder Threaded Binary Tree and Traverse
it in Inorder and Preorder way.*/
#include <stdio.h>
#include <stdlib.h>


// Define the structure of threaded binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
    int isThreaded;
};

// Create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->isThreaded = 0;
    return node;
}

// Insert a node into the threaded binary tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        if (root->isThreaded == 1) {
            struct node* temp = root->right;
            root->right = newNode(data);
            root->isThreaded = 0;
            root->right->left = temp;
            root->right->isThreaded = 1;
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Inorder traversal of the threaded binary tree
void inorder(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        while (current->left != NULL) {
            current = current->left;
        }
        printf("%d ", current->data);
        while (current->isThreaded == 1) {
            current = current->right;
            printf("%d ", current->data);
        }
        current = current->right;
    }
}

// Preorder traversal of the threaded binary tree
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        if (root->left != NULL && root->left->isThreaded == 0) {
            preorder(root->left);
        }
        if (root->right != NULL && root->right->isThreaded == 0) {
            preorder(root->right);
        }
    }
}

// Postorder traversal of the threaded binary tree
void postorder(struct node* root) {
    if (root != NULL) {
        if (root->left != NULL && root->left->isThreaded == 0) {
            postorder(root->left);
        }
        if (root->right != NULL && root->right->isThreaded == 0) {
            postorder(root->right);
        }
        printf("%d ", root->data);
    }
}

// Main function to create and traverse a threaded binary tree
int main() {
    struct node* root = NULL;
    root = insert(root, 6);
    
     insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 5);
    insert(root, 7);
    insert(root, 9);
    root->left->right->right = root;
    root->left->right->isThreaded = 1;
    printf("Inorder traversal of the threaded binary tree: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal of the threaded binary tree: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal of the threaded binary tree: ");
    postorder(root);
return 0;
}