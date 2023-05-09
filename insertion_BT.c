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
return 0;
}