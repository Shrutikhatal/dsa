#include <stdio.h>
#include <stdlib.h>

// define a structure for a node in the binary tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// non-recursive inorder traversal
void inorder(struct node* root) {
    struct node* stack[100];
    int top = -1;
    struct node* current = root;

    while (1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        if (top == -1) {
            break;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// non-recursive preorder traversal
void preorder(struct node* root) {
    struct node* stack[100];
    int top = -1;
    struct node* current = root;

    while (1) {
        while (current != NULL) {
            printf("%d ", current->data);
            stack[++top] = current;
            current = current->left;
        }
        if (top == -1) {
            break;
        }
        current = stack[top--];
        current = current->right;
    }
}

// display number of leaf nodes
int countLeaves(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// create a mirror image of the binary tree
void mirror(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Number of Leaf Nodes: %d\n", countLeaves(root));

    printf("Mirror Image: \n");
    mirror(root);
    inorder(root);
    printf("\n");

    return 0;
}
