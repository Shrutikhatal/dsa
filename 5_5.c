#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *next;
};

void print(struct node *head)
{
    while (head->next != NULL)
    {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next != NULL && head->next->coeff >= 0)
        {
            printf("+");
        }
        head = head->next;
    }
    printf("%d\n", head->coeff);
}

void print_with_addresses(struct node *head)
{
    while (head != NULL)
    {
        printf("coeff:%d - power:%d - current_node_address:%p - next_node_address:%p \n", head->coeff, head->power, head, head->next);
        head = head->next;
    }
    printf("\n\n");
}

void nodeInsert(struct node **head, int coeff, int pow)
{
    if ((*head) == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->power = pow;
        newnode->coeff = coeff;
        (*head) = newnode;
        newnode->next = NULL;
        return;
    }
    else
    {
        struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
        newnode1->coeff = coeff;
        newnode1->power = pow;
        struct node *temp1 = (*head);
        while (temp1->next != NULL)
        {
            // printf("%d HI", pow);
            temp1 = temp1->next;
            // printf("%d LOW", pow);
        }
        temp1->next = newnode1;
        newnode1->next = NULL;
        // printf("HJO");
        return;
    }
}

void polynomialCreating(struct node **head)
{
    int x;
    do
    {
        int coeff;
        printf("Enter coefficient\n");
        scanf("%d", &coeff);
        int power;
        printf("Enter Power\n");
        scanf("%d", &power); 

        nodeInsert(&(*head), coeff, power);

        printf("If want to add more terms press 1 and if want to step press 0-->\n");
        scanf("%d", &x);
    } while (x);
}

void removeduplicates(struct node **head)
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = *head;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {

            if (ptr1->power == ptr2->next->power)
            {

                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;

                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void multiply(struct node **head1, struct node **head2, struct node **head3)
{

    struct node *ptr1 = *head1;
    struct node *ptr2 = *head2;
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            int coeff, power;
            coeff = ptr1->coeff * ptr2->coeff;
            power = ptr1->power + ptr2->power;
            nodeInsert(&(*head3), coeff, power);
            ptr2 = ptr2->next;
        }
        ptr2 = *head2;
        ptr1 = ptr1->next;
    }
    removeduplicates(&(*head3));
}

int main()
{

    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    printf("\nENTER DATA FOR POLYNOMIAL-1\n");
    polynomialCreating(&head1);
    printf("\nYOUR ENTERED POLYNOMIAL-1 : ");
    print(head1);

    printf("\nENTER DATA FOR POLYNOMIAL-2\n");
    polynomialCreating(&head2);
    printf("\nYOUR ENTERED POLYNOMIAL-2 : ");
    print(head2);

    multiply(&head1, &head2, &head3);
    printf("\nMULTIPLICATION OF BOTH POLYNOMIALS :\n");
    print(head3);

    printf("\n\n");
    printf("*****POLYNOMIAL-1******\n");
    print_with_addresses(head1);
    printf("*****POLYNOMIAL-2******\n");
    print_with_addresses(head2);
    printf("*****POLYNOMIAL-3******\n");
    print_with_addresses(head3);
return 0;
}