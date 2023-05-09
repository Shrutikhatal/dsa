#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define max_size 100

char stack[max_size];
int top=-1;
void push(char element){
    if(top>=max_size-1){
        printf("stack overflow");

    }else{
        top++;
        stack[top]=element;
    }
}

char pop(){
    char poppped;
    if(top==-1) printf("stack underflow");
    else{
        poppped=stack[top];
        top--;
        return poppped;
    }
}

bool isvalidparenthesis(char * parenthesis){
    int length=strlen(parenthesis);
    for(int i=0;i<length;i++){
        if(parenthesis[i]=='('){
            push('(');
        }else if(parenthesis[i]==')'){
            if(top==-1){
                return false;
            }else pop();
        }
    }
    if(top==-1){
        return true;

    }else return false;
}
int main()
{
    char parentheses[max_size];
    printf("Enter string parenthesis:");
    scanf("%s", parentheses);
    if(isvalidparenthesis(parentheses)){
        printf("valid parenthesis");
    }else printf("Invalid");

return 0;
}