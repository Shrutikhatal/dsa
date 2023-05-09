/*
Write a Program to create a Binary Search Tree and perform
following nonrecursive operations on it. a. Preorder Traversal b.
Inorder Traversal c. Display Number of Leaf Nodes d. Mirror Image

*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
     struct node* left;
     struct node* right;
 };
struct node* createnode(int val){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->val=val;
    new_node->right=NULL;
    new_node->right=NULL;
    return new_node;

}

struct node* insertNode(struct node* root, int val) {
   if(root==NULL) return createnode(val);
   else if(val < root->val){
    root->left=insertNode(root->left , val);
   }else if(val> root->val){
    root->right=insertNode(root->right , val);
   }
   return root;
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    struct node* stack[100];
    int top=-1;
    stack[++top]=root;
    while(top>=0){
        struct node* temp=stack[top--];
        printf("%d ", temp->val);
        if (temp->right) {
            stack[++top] = temp->right;
        }
        if (temp->left) {
            stack[++top] = temp->left;
        }
    }
}
// Inorder traversal (non-recursive)
void inorder_traversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* stack[100]; // Stack to store nodes
    int top = -1; // Stack pointer
    struct node* temp = root;
    while (temp != NULL || top >= 0) {
        while (temp != NULL) {
            stack[++top] = temp;
            temp = temp->left;
        }
        temp = stack[top--];
        printf("%d ", temp->val);
        temp = temp->right;
    }
}
int count_leaf_nodes(struct node* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
    }
}

// Function to create mirror image of BST
struct node* mirror_image(struct node* root) {
    if (root == NULL) {
        return NULL;
    } else {
        struct node* temp_node = root->left;
        root->left = mirror_image(root->right);
        root->right = mirror_image(temp_node);
        return root;
    }
}

int main() {
    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\nInorder traversal: ");
    inorder_traversal(root);
    printf("\nNumber of leaf nodes: %d", count_leaf_nodes(root));
    printf("\nMirroring the tree...\n");
    root = mirror_image(root);
    printf("Preorder traversal after mirroring: ");
    preorder(root);
    printf("\nInorder traversal after mirroring: ");
    inorder_traversal(root);
    printf("\nNumber of leaf nodes after mirroring: %d", count_leaf_nodes(root));

    return 0;
}
