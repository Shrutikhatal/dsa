#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char code[20];
    char name[50];
    float price;
    int stock;
    char received[20];
    char expires[20];
    struct product *left;
    struct product *right;
};

struct product *create_product(char code[], char name[], float price, int stock, char received[], char expires[]) {
    struct product *new_product = (struct product*) malloc(sizeof(struct product));
    strcpy(new_product->code, code);
    strcpy(new_product->name, name);
    new_product->price = price;
    new_product->stock = stock;
    strcpy(new_product->received, received);
    strcpy(new_product->expires, expires);
    new_product->left = NULL;
    new_product->right = NULL;
    return new_product;
}

struct product *insert_product(struct product *root, char code[], char name[], float price, int stock, char received[], char expires[]) {
    if (root == NULL) {
        return create_product(code, name, price, stock, received, expires);
    } else if (strcmp(code, root->code) < 0) {
        root->left = insert_product(root->left, code, name, price, stock, received, expires);
    } else if (strcmp(code, root->code) > 0) {
        root->right = insert_product(root->right, code, name, price, stock, received, expires);
    } else {
        printf("Product with code %s already exists.\n", code);
    }
    return root;
}

struct product *find_product(struct product *root, char code[]) {
    if (root == NULL) {
        printf("Product with code %s not found.\n", code);
        return NULL;
    } else if (strcmp(code, root->code) < 0) {
        return find_product(root->left, code);
    } else if (strcmp(code, root->code) > 0) {
        return find_product(root->right, code);
    } else {
        return root;
    }
}

void update_product(struct product *product, char code[], char name[], float price, int stock, char received[], char expires[]) {
    strcpy(product->code, code);
    strcpy(product->name, name);
    product->price = price;
    product->stock = stock;
    strcpy(product->received, received);
    strcpy(product->expires, expires);
    printf("Product with code %s updated.\n", code);
}

void list_products(struct product *root) {
    if (root != NULL) {
        list_products(root->left);
        if (strcmp(root->expires, "N/A") != 0) {
            printf("%s, %.2f, %d, %s, %s\n", root->name, root->price, root->stock, root->received, root->expires);
        }
        list_products(root->right);
    }
}

int main() {
    struct product *root = NULL;
    int choice;
    char code[20], name[50], received[20], expires[20];
    float price;
    int stock;

    do {
        printf("\n=== Product Inventory System ===\n");
        printf("1. Add product\n");
        printf("2. Find product\n");
        printf("3. Update product\n");
        printf("4. List products\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product code: ");
                scanf("%s", code);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%f", &price);
                printf("Enter product stock: ");
                scanf("%d", &stock);
                printf("Enter date received (YYYY-MM-DD): ");
                scanf("%s", received);
                printf("Enter expiration date (YYYY-MM-DD) or N/A: ");
                scanf("%s", expires);
                root = insert_product(root, code, name, price, stock, received, expires);
                break;
            case 2:
                printf("Enter product code: ");
                scanf("%s", code);
                struct product *p = find_product(root, code);
                if (p != NULL) {
                    printf("%s, %.2f, %d, %s, %s\n", p->name, p->price, p->stock, p->received, p->expires);
                }
                break;
            case 3:
                printf("Enter product code: ");
                scanf("%s", code);
                struct product *q = find_product(root, code);
                if (q != NULL) {
                    printf("Enter new product name: ");
                    scanf("%s", name);
                    printf("Enter new product price: ");
                    scanf("%f", &price);
                    printf("Enter new product stock: ");
                    scanf("%d", &stock);
                    printf("Enter new date received (YYYY-MM-DD): ");
                    scanf("%s", received);
                    printf("Enter new expiration date (YYYY-MM-DD) or N/A: ");
                    scanf("%s", expires);
                    update_product(q, code, name, price, stock, received, expires);
                }
                break;
            case 4:
                printf("Product Name, Price, Stock, Received, Expires\n");
                printf("------------------------------------------------\n");
                list_products(root);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}