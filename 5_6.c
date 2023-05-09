#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} node;

struct node *createLinkedList(int n);
void displayList(struct node *head);
struct node *copyList(struct node *head);

int main()
{
    int n = 0;
    struct node *HEAD = NULL;
    printf("\nHow  many nodes: ");
    scanf("%d", &n);
    HEAD = createLinkedList(n);
    printf("Original List : \n");
    displayList(HEAD);
    printf("Duplicate List : \n");
    struct node *copy = copyList(HEAD);
    displayList(copy);
    
    return 0;
}

struct node *createLinkedList(int n)
{
    int i = 0;
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *p = NULL;

    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(node));
        printf("\nEnter the data for node number %d : ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    return head;
}

void displayList(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d->  ", p->data);
        printf("Address of Current Node : %p  ", p);
        p = p->next;
        printf("Address of Next Node : %p\n", p);
    }
    printf("NULL\n");

}

struct node *copyList(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node)); 
        newNode->data = head->data;
        newNode->next = copyList(head->next);
        return newNode;
    }
}