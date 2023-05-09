#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stack_size 100
struct stack
{
 int top;
 char stack_item[stack_size][100];
};
void push(struct stack *s, char item[])
{
if (s->top == stack_size - 1)
printf("%s", "Invalid Expression\n");
 else
 {
 s->top += 1;
strcpy(s->stack_item[s->top], item);
 }
}
char *pop(struct stack *s)
{
 if (s->top == -1)
 {
 printf("%s", "Invalid Expression\n");
 exit(1);
 }
 else
 {
 return s->stack_item[s->top--];
 }
}
int operate(char a[], char b[], char c)
{
 if (c == '+')
 {
 return atoi(a) + atoi(b);
 }
 else if (c == '-')
 {
 return atoi(a) - atoi(b);
 }
 else if (c == '*')
 {
 return atoi(a) * atoi(b);
 }
 else if (c == '/')
 {
 return atoi(a) / atoi(b);
 }
 return 0;
}
void evaluate(char prefix[])
{
 char string3[100];
 int ans;
 struct stack s;
 s.top = -1;
 for (int i = strlen(prefix) - 1; i >= 0; i--)
 {
 if (prefix[i] >= '0' && prefix[i] <= '9')
 {
 char temp[] = {prefix[i], '\0'};
 push(&s, temp);
 }
 else
 {
 char *string2 = pop(&s);
 char *string1 = pop(&s);
 ans = operate(string1, string2, prefix[i]);
 sprintf(string3, "%d", ans);
 push(&s, string3);
 }
 }
 printf("%d\n", ans);

}
void convert(char prefix[])
{
 char *string1;
 char *string2;
 char string3[100];

 char infix[100];
 struct stack s;
 s.top = -1;
for (int i = strlen(prefix) - 1; i >= 0; i--)
 {
if (prefix[i] >= '0' && prefix[i] <= '9')
 {
 char temp[] = {prefix[i], '\0'};
 push(&s, temp);
 }
 else
 {
 char temp[] = {prefix[i], '\0'};
 string2 = pop(&s);
 string1 = pop(&s);

 strcat(string3, "(\0");
 strcat(string3, string2);
 strcat(string3, temp);
 strcat(string3, string1);
 strcat(string3, ")\0");

 push(&s, string3);
 strcpy(string3, "\0");
 }
 }
 printf("%s\n", s.stack_item[0]);

}

int main()
{
 char prefix[100];
 printf("Enter a prefix expression: ");
 scanf("%s", prefix);
convert(prefix);
 evaluate(prefix);
}