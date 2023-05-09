#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* left;
    struct node* right;
};

struct node* new_node(int val) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* root, int val) {
    if (root == NULL) {
        return new_node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

struct node* delete(struct node* root, int val) {
    if (root == NULL) {
        return root;
    }
    if (val < root->val) {
        root->left = delete(root->left, val);
    } else if (val > root->val) {
        root->right = delete(root->right, val);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->val = temp->val;
        root->right = delete(root->right, temp->val);
    }
    return root;
}
void level_order_traversal(struct node * root){
    if(root==NULL) return;
    struct node* queue[1000];
    int front, rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node* current=queue[front++];
        printf("%d ", current->val);
        if(current->left!=NULL){
            queue[rear++]=current->left;
        }
         if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}


int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Level order traversal of the binary search tree:\n ");
    level_order_traversal(root);

    root = delete(root, 20);
    root = delete(root, 30);
    root = delete(root, 50);

    printf("\nLevel order traversal of the modified binary search tree: \n");
    level_order_traversal(root);
    return 0;
}
