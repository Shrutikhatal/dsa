/*Write a c program to efficiently search a perticular employee record
by using Tree data structure. Also sort the data on empid in
ascending order.*/
#include <stdio.h>
#include <stdlib.h>

struct employee {
    int empid;
    char name[50];
    float salary;
};

struct node {
    struct employee data;
    struct node* left;
    struct node* right;
};

void insert(struct node** root, struct employee data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
        *root = new_node;
    } else if (data.empid < (*root)->data.empid) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t%s\t%f\n", root->data.empid, root->data.name, root->data.salary);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int empid) {
    if (root == NULL || root->data.empid == empid) {
        return root;
    } else if (root->data.empid > empid) {
        return search(root->left, empid);
    } else {
        return search(root->right, empid);
    }
}

int main() {
    struct node* root = NULL;
    struct employee e1 = { 1001, "John Doe", 5000.00 };
    struct employee e2 = { 1003, "Jane Smith", 6000.00 };
    struct employee e3 = { 1005, "Bob Johnson", 7000.00 };
    struct employee e4 = { 1002, "Mary Brown", 5500.00 };
    struct employee e5 = { 1004, "Tom Wilson", 6500.00 };

    insert(&root, e1);
    insert(&root, e2);
    insert(&root, e3);
    insert(&root, e4);
    insert(&root, e5);

    printf("Employee ID\tName\tSalary\n");
    inorder(root);

    int search_id = 1003;
    struct node* search_result = search(root, search_id);
    if (search_result != NULL) {
        printf("Found employee with ID %d: %s\t%f\n", search_id, search_result->data.name, search_result->data.salary);
    } else {
        printf("Employee with ID %d not found.\n", search_id);
    }

    return 0;
}
