#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CUSTOMERS 50

int customers[MAX_CUSTOMERS];
int num_customers = 0;
int num_tellers = 1;
int time_now = 0;

void add_customer() {
    if (num_customers >= MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached.\n");
        return;
    }
    customers[num_customers] = time_now;
    num_customers++;
}

void serve_customers() {
    int i = 0;
    int served_customers = 0;
    while (i < num_customers) {
        if (served_customers < num_tellers) {
            int wait_time = time_now - customers[i];
            printf("Customer %d served after waiting %d minutes.\n", i+1, wait_time);
            served_customers++;
            i++;
        } else {
            break;
        }
    }
    num_customers -= served_customers;
    for (int j = 0; j < num_customers; j++) {
        customers[j] = customers[j+served_customers];
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        add_customer();
    }
    while (num_customers > 0) {
        serve_customers();
        time_now += rand() % 6 + 1; // Generate a random service time between 1 and 6 minutes
    }
    return 0;
}
