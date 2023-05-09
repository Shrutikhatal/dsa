#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
# define max 100
int top=-1;
char stack[max];
int isfull(){
    return top==max-1;
}
int isempty(){
    return top==-1;
}
void push(char item){
    if(isfull()) return;
    top++;
    stack[top]=item;
}
void pop(){
    if(isempty()) 
 return INT_MIN;
    stack[top--]
}
int peek(){
    if(isempty()){
        return INT_MIN;
        return stack[top];
    }
}
int checkifoperand(char ch){
    return (ch>='a'&& ch<='z' || ch>='A'&& ch<='Z')
}
int precedance(char ch){
    switch (ch){
        case '+':
        case '-':
        return 1;

        case '*':
        case '/':
        return 2;
        case '^':
         return 3;

    }
    return -1;
}
int getpostfix(char* expression){
    int i, j;
    for(int i=0, j=-1; expression[i];++i){
        if(checkifoperand(expression[i]))
        expression[++j]=expression[i];
        else if(expression[i]=='(')
        push(expression[i]);
        else if(expression[i]==')'){
            while(!isempty(stack)&& peek(stack)!='(')
            expression[++j]=pop(stack);
            if(!isempty(stack)&& peek(stack)!='(')
            return -1;
            else pop(stack);
        }else{
            while( !isempty(stack)&& precedance(expression[i] <= precedance(peek(stack))))
            expression[++j]=pop(stack);
            push(expression[i]);
        }

    }
    while(!isempty(stack))
    expression[++j]='\0';
}

void reverse(char * exp){
    
}
int main()
{

return 0;
}