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

struct node* find(struct node* root , int val){
if(root==NULL || root->val==val){
    return root;
}else if(val < root->val){
    return find(root->left, val);
}else {
    return find(root->right , val);
}
}

void show(struct node* root){
    if(root!=NULL){
        show(root->left);
        printf("%d ", root->val);
        show(root->right);
    }
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

int main(){

struct node* root=NULL;
int choice , val;
while(1){
    printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Find\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;
             case 3:
                printf("Enter key to find: ");
                scanf("%d", &val);
                if (find(root, val) != NULL) {
                    printf("Key found\n");
                }
                else {
                    printf("Key not found\n");
                }
                break;
            case 4:
                printf("BST contents: ");
                show(root);
                printf("\n");
                break;

            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
    
}

}
    return 0;
}