
/*Write a Program to create a Binary Search Tree and perform deletion
of a node from it. Also display the tree in nonrecursive postorder way*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node * left;
     struct node * right;

};
struct node * createnode(int val){
    struct node * new_node=(struct node *)malloc(sizeof(struct node));
    new_node->val=val;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;

}
struct node * insert(struct node *root  , int val ){
    if(root==NULL) return createnode(val);
    if(root->val> val){
      root->left=insert(root->left , val);
    }
   else if(root->val < val){
        root->right=insert(root->right, val);
    }
    return root;

}

struct node* delete(struct node* root, int val){
if(root==NULL) return root;
if(val<root->val){
    root->left=delete(root->left, val);
}else if(val> root->val){
    root->right=delete(root->right ,val);
}else{
    if(root->left==NULL){
        struct node * temp=root->right;
        free(root);
        return temp;
    }else if(root->right==NULL){
        struct node * temp=root->left;
        free(root);
        return temp;
    }
    struct node* temp=root->right;
    while(temp->left !=NULL){
            temp=temp->left;
    }
    root->val=temp->val;
    root->right=delete(root->right, temp->val);

}
return root;
}
void postorder(struct node *root) {
    if(root == NULL) {
        return;
    }

    struct node *stack[100];
    int top = -1;
    struct node *curr = root;
    struct node *prev = NULL;

    while(curr != NULL || top != -1) {
        while(curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top];

        if(curr->right == NULL || curr->right == prev) {
            printf("%d ", curr->val);
            prev = curr;
            curr = NULL;
            top--;
        } else {
            curr = curr->right;
        }
    }
}
int main() {
    struct node *root = NULL;

    // Insert nodes into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display the tree in non-recursive postorder traversal
    printf("Non-recursive postorder traversal: ");
    postorder(root);

    // Delete a node from the tree
    root = delete(root, 20);
    printf("\nTree after deleting node with value 20: ");
    postorder(root);

    return 0;
}
