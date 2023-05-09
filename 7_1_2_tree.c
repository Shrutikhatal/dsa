
// counting no no nodes and height of tree
#include<stdio.h>
#include<stdlib.h>
#define max 100

struct node {
int data;
struct node * left;
 struct node* right;

};
struct node * createnode(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
     new_node->right=NULL;
     return new_node;
}

void insert(struct node ** root , int data){
struct node * new_node=createnode(data);
if(*root==NULL){
    *root=new_node;
    return;
}
struct node * temp=*root;
struct node *prev=NULL;
while(temp!=NULL){
    prev=temp;
    if(data< temp->data){
        temp=temp->left;
    }else{
        temp=temp->right;
    }
}

if(data < prev->data){
    prev->left=new_node;
}else{
    prev->right=new_node;
}

}

int countnode(struct node * root){
    if(root==NULL){
        return 0;
    }
    struct node *stack[max];
    int top=-1, count =0;
    stack[++top]=root;
    while(top!=-1){
        struct node * new_node=stack[top--];
        count++;
        if(new_node->right !=NULL){
            stack[++top]=new_node->right;
        }
        if(new_node->left!=NULL){
            stack[++top]=new_node->left;
        }
    }
    return count;
}
int getheight(struct node * root){
    if(root==NULL){
        return 0;
    }
    int leftheight=getheight(root->left);
    int rightheight=getheight(root->right);
    return 1+(leftheight >rightheight ? leftheight : rightheight);
}
int main()
{
struct node * root=NULL;
insert(&root , 50);
insert(&root , 30);
insert(&root , 70);
insert(&root , 20);
insert(&root , 40);
insert(&root , 60);
insert(&root , 80);

printf("Total nodes in tree : %d \n", countnode(root));
printf("Height of tree : %d\n", getheight(root));
return 0;
}