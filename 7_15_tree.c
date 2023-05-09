/*Write a program, using trees, to assign the roll nos. to the students of
your class as per their previous years result. i.e topper will be roll
no. 1.
*/
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the tree
struct node {
    int roll_no;
    int marks;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given roll number and marks
struct node* create_node(int roll_no, int marks) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->roll_no = roll_no;
    new_node->marks = marks;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the tree
struct node* insert_node(struct node* root, int roll_no, int marks) {
    if (root == NULL) {
        return create_node(roll_no, marks);
    } else if (marks > root->marks) {
        root->left = insert_node(root->left, roll_no, marks);
    } else {
        root->right = insert_node(root->right, roll_no, marks);
    }
    return root;
}

// Function to traverse the tree and assign roll numbers
void assign_roll_numbers(struct node* root, int* roll_no_ptr) {
    if (root == NULL) {
        return;
    }
    assign_roll_numbers(root->left, roll_no_ptr);
    root->roll_no = (*roll_no_ptr)++;
    assign_roll_numbers(root->right, roll_no_ptr);
}

// Function to print the roll numbers of all the nodes in the tree
void print_roll_numbers(struct node* root) {
    if (root == NULL) {
        return;
    }
    print_roll_numbers(root->left);
    printf("Roll No. %d - Marks: %d\n", root->roll_no, root->marks);
    print_roll_numbers(root->right);
}

int main() {
    // Example data
    int marks[] = {90, 80, 95, 85, 75};
    int num_students = sizeof(marks) / sizeof(marks[0]);
    
    // Create a binary search tree based on the marks
    struct node* root = NULL;
    for (int i = 0; i < num_students; i++) {
        root = insert_node(root, i + 1, marks[i]);
    }
    
    // Traverse the tree and assign roll numbers
    int roll_no = 1;
    assign_roll_numbers(root, &roll_no);
    
    // Print the roll numbers of all the nodes in the tree
    print_roll_numbers(root);
    
    return 0;
}
