/*
Write a Program to create a Binary Search Tree and perform
following nonrecursive operations on it. a. Preorder Traversal b.
Postorder Traversal c. Display total Number of Nodes d. Display
Leaf nodes.*/
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
// non recursive
int countnode(struct node* root){
    if(root==NULL) return 0;
    int count=0;
    struct node* stack[100];
    int top=-1;
    stack[++top]=root;
    while(top>=0){
        root=stack[top--];
        count++;
        if(root->right!=NULL){
            stack[++top]=root->right;
        }if(root->left!=NULL){
            stack[++top]=root->left;
        }
    }
    return count;
}

void displayleafnode(struct node* root){
    if(root==NULL) return;
    struct node * stack[100];
    int top=-1;
    stack[++top]=root;
    while(top>=0){
        root=stack[top--];
     if(root->right!=NULL){
            stack[++top]=root->right;
        }
    if(root->left!=NULL){
            stack[++top]=root->left;
        }
    if(root->left==NULL && root->right==NULL){
        printf("%d ",root->val);
    }
    }
}
int main(){
 struct node* root=NULL;
    root=insertNode(root, 10);
    insertNode(root, 6);
    insertNode(root, 3);
    insertNode(root, 8);
    insertNode(root, 13);
    insertNode(root, 11);
    insertNode(root, 15);

    printf("Preorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    printf("\nNumber of nodes in the tree: %d", countnode(root));

    printf("\nLeaf nodes: ");
    displayleafnode(root);
    return 0;
}