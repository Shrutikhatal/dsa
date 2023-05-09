#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
int top = -1;
char stack[50][50];

void clear_stack();
void push(char *s);
char *pop();
int is_operator(char x);
void convert(char *exp);

int main()
{
    char prefix[MAX_SIZE];
    printf("\nEnter a prefix expression: ");
    scanf("%s", prefix);
    convert(prefix);
    return 0;
}

void clear_stack()
{
    top = -1;
}

void push(char *s)
{
    strcpy(stack[++top], s);
}

char *pop()
{
    return stack[top--];
}

int is_operator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void convert(char *exp)
{
    clear_stack();
    int i, l, m;
    char op1[50], op2[50];

    l = strlen(exp);
    bool cheak1 = exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/';
    bool cheak2 = exp[l - 1] == '+' || exp[l - 1] == '-' || exp[l - 1] == '*' || exp[l - 1] == '/';
    if (cheak1 && !cheak2)
    {
        for (i = l - 1; i >= 0; i--)
        {
            if (is_operator(exp[i]))
            {

                strcpy(op1, pop());
                strcpy(op2, pop());

                strcat(op1, strcat(op2, (char[2]){(char)exp[i], '\0'}));
                push(op1);
            }
            else
            {
                push((char[2]){(char)exp[i], '\0'});
            }
        }
        m = strlen(stack[top]);
        if (m == l)
        {
            printf("\nEquivalent postfix expression : %s\n\n", stack[top]);
        }
        else
            printf("\nInvalid Prefix Expression\n\n");
    }
    else
        printf("\nInvalid Prefix Expression \n\n");
}