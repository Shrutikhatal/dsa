/*Write a Program to create a Binary Search Tree and display its mirror
image with and without disturbing the original tree. Also display
height of a tree using nonrecursion. in c*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in BST
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function to insert a new node in BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return(newNode(data));
    }
    else {
        if (data <= node->data) {
            node->left = insert(node->left, data);
        }
        else {
            node->right = insert(node->right, data);
        }
        return(node);
    }
}

// Function to display the mirror image of a BST
void mirror(struct Node* node) {
    if (node == NULL) {
        return;
    }
    else {
        struct Node* temp;
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

// Function to display the height of a BST using non-recursion
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int height = 0;
    struct Node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            current = current->right;
            height++;
        }
        else {
            struct Node* pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
                height++;
            }
            else {
                pre->right = NULL;
                current = current->right;
            }
        }
    }
    return height;
}

// Function to print the BST in inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver program to test above functions
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the original tree:\n");
    inorder(root);
    printf("\n");
    mirror(root);
    printf("Inorder traversal of the mirror tree:\n");
    inorder(root);
    printf("\n");
    printf("Height of the tree is: %d\n", height(root));
    return 0;
}
