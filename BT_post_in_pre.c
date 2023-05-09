// recursive 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node * left;
     struct node * right;
};

struct node* createnode(int value){
    struct node* new_node=malloc(sizeof(struct  node));
    new_node->value=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
struct node* insert(struct node * root , int value){
    if(root==NULL) return createnode(value);
    if(root->value < value)
   root->right=insert(root->right, value);
if(root->value> value)
root->left=insert(root->left, value);
return root;
}
void insertoeder(struct node* root){
    if(root==NULL) return ;
    printf("%d\n",root->value);
   insertoeder(root->left);
   
   insertoeder(root->right);
    
}

void inorder(struct node * root){
    if(root==NULL) return ;
    inorder(root->left);
    printf("%d ",root->value);
    inorder(root->right);

}
void preorder(struct node * root){
    if(root==NULL) return ;
     printf("%d ",root->value);
    preorder(root->left);
   
    preorder(root->right);
    
}
void postorder(struct node * root){
    if(root==NULL) return ;
    postorder(root->left);
   
    postorder(root->right);
     printf("%d ",root->value);
    
}
int main()
{
struct node* root=NULL;
root=insert(root,7);
root=insert(root,4);
root=insert(root,8);
root=insert(root,1);
root=insert(root,5);
root=insert(root,2);
root=insert(root,9);
root=insert(root,3);
insertoeder(root);

printf("Inorder\n ");
inorder(root);

printf("\npreorder\n ");
preorder(root);

printf("\npostorder\n ");
postorder(root);
return 0;
}