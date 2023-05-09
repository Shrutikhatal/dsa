#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct Product {
    int code;
    char name[100];
    float price;
    int stock;
    struct Date received;
    struct Date expiration;
    struct Product* left;
    struct Product* right;
};

struct Product* createProduct(int code, char name[], float price, int stock, struct Date received, struct Date expiration) {
    struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
    newProduct->code = code;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->stock = stock;
    newProduct->received = received;
    newProduct->expiration = expiration;
    newProduct->left = NULL;
    newProduct->right = NULL;
    return newProduct;
}

struct Product* insertProduct(struct Product* root, struct Product* product) {
    if (root == NULL) {
        return product;
    }

    if (product->code < root->code) {
        root->left = insertProduct(root->left, product);
    } else if (product->code > root->code) {
        root->right = insertProduct(root->right, product);
    }

    return root;
}

void prefixOrderTraversal(struct Product* root) {
    if (root != NULL) {
        prefixOrderTraversal(root->left);
        printf("Name: %s\tCode: %d\n", root->name, root->code);
        prefixOrderTraversal(root->right);
    }
}

void listAllItems(struct Product* root) {
    if (root != NULL) {
        listAllItems(root->left);
        printf("Name: %s\tCode: %d\tPrice: %.2f\tStock: %d\tReceived: %02d/%02d/%d\tExpiration: %02d/%02d/%d\n",
               root->name, root->code, root->price, root->stock,
               root->received.day, root->received.month, root->received.year,
               root->expiration.day, root->expiration.month, root->expiration.year);
        listAllItems(root->right);
    }
}

struct Product* deleteProduct(struct Product* root, int code) {
    if (root == NULL) {
        return root;
    }

    if (code < root->code) {
        root->left = deleteProduct(root->left, code);
    } else if (code > root->code) {
        root->right = deleteProduct(root->right, code);
    } else {
        if (root->left == NULL) {
            struct Product* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Product* temp = root->left;
            free(root);
            return temp;
        }

        struct Product* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->code = temp->code;
        strcpy(root->name, temp->name);
        root->price = temp->price;
        root->stock = temp->stock;
        root->received = temp->received;
        root->expiration = temp->expiration;

        root->right = deleteProduct(root->right, temp->code);
    }

    return root;
}
int isExpired(struct Product* product) {
    // Get the current date
    struct Date currentDate;
    // You need to implement code to get the current date and store it in the currentDate variable

    // Compare the current date with the expiration date
    if (currentDate.year > product->expiration.year) {
        return 1;  // Product is expired if current year is greater than expiration year
    } else if (currentDate.year == product->expiration.year) {
        if (currentDate.month > product->expiration.month) {
            return 1;  // Product is expired if current month is greater than expiration month
        } else if (currentDate.month == product->expiration.month) {
            if (currentDate.day > product->expiration.day) {
                return 1;  // Product is expired if current day is greater than expiration day
            }
        }
    }

    return 0;  // Product is not expired
}

struct Product* deleteExpiredItems(struct Product* root) {
    if (root == NULL) {
        return root;
    }

    root->left = deleteExpiredItems(root->left);
    root->right = deleteExpiredItems(root->right);

    if (isExpired(root)) {
        root = deleteProduct(root, root->code);
    }

    return root;
}


int main() {
    struct Product* root = NULL;
    
    struct Date received = {1, 5, 2023};
    struct Date expiration = {1, 7, 2023};
    
    struct Product* p1 = createProduct(1001, "Product 1", 10.50, 50, received, expiration);
    struct Product* p2 = createProduct(1002, "Product 2", 5.25, 100, received, expiration);
    struct Product* p3 = createProduct(1003, "Product 3", 20.00, 10, received, expiration);
    struct Product* p4 = createProduct(1004, "Product 4", 15.75, 25, received, expiration);
    struct Product* p5 = createProduct(1005, "Product 5", 8.99, 75, received, expiration);
    
    root = insertProduct(root, p1);
    root = insertProduct(root, p2);
    root = insertProduct(root, p3);
    root = insertProduct(root, p4);
    root = insertProduct(root, p5);
    
    printf("All Items:\n");
    listAllItems(root);
    
    printf("\nDeleting item with code 1003...\n");
    root = deleteProduct(root, 1003);
    
    printf("\nAll Items after deleting item with code 1003:\n");
    listAllItems(root);
    
    printf("\nDeleting expired items...\n");
    root = deleteExpiredItems(root);
    
    printf("\nAll Items after deleting expired items:\n");
    listAllItems(root);
    
    return 0;
}
