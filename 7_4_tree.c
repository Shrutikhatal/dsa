#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
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

struct Node * insert(struct Node *root  , int val ){
    if(root==NULL) return newNode(val);
    if(root->data> val){
      root->left=insert(root->left , val);
    }
   else if(root->data < val){
        root->right=insert(root->right, val);
    }
    return root;

}
struct Node* find(struct Node* root , int val){
if(root==NULL || root->data==val){
    return root;
}else if(val < root->data){
    return find(root->left, val);
}else {
    return find(root->right , val);
}
}

struct Node* mirrorImage(struct Node* root) {
    if (root == NULL) {
        return;
    }
    mirrorImage(root->left);
    mirrorImage(root->right);
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return mirrorImage;
}

int main()
{
struct node* root = NULL;
    int choice, data, key;
    while (1) {
     printf("\nBinary Search Tree Operations\n");
    printf("1. Insert\n");
    printf("2. Mirror Image\n");
    printf("3. Find\n");
    printf("4. Postorder (nonrecursive)\n");
    printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                mirrorImage(root);
                printf("The mirror image of the tree has been created.\n");
               
                break;
            case 3:
                printf("Enter the key to be searched: ");
                scanf("%d", &key);
                if (find(root, key) != NULL) {
                    printf("The key %d has been found in the tree.\n", key);
                } else {
                    printf("The key %d has not been found in the tree.\n", key);
                }
                break;
            case 4:
                printf("The postorder traversal of the tree is: \n");
                postOrder(root);
                break;
             default:
             printf(" Invalid choice");   
        }
    }
return 0;
}